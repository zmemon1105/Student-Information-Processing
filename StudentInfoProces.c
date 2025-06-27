#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct student{
int ID;
char firstName[20];
char lastName[20];
float GPA;

}Student;
void searchStudentRecords(Student studentArr[], int index);
int searchStudentID(Student studentArr[], int index, int ID);

void readingFile(){
    int index = 0;
     char fileName[30];
    FILE* input;
 printf("Enter the file name to process:");
    scanf("%s", fileName);
    input = fopen(fileName, "r");

    Student studentArr[100];

  
   while(fscanf(input, "%d %s %s %f", 
   &studentArr[index].ID, 
   studentArr[index].firstName, 
   studentArr[index].lastName, 
   &studentArr[index].GPA) == 4){

    if (index > 0 && studentArr[index].ID <= studentArr[index -1].ID){
        printf("File is not in order.\n");
        fclose(input);
        break;
    }

    index++;
    if(index>=100) break;
   }
       
    searchStudentRecords(studentArr, index);
    fclose(input);
}
void searchStudentRecords(Student studentArr[], int index){
    int ID;
    int result;

    while(1){
    printf("Enter student ID to search or -1 to quit: ");
    scanf("%d", &ID);

        if(ID == -1){break;}

        else {
        result  = searchStudentID(studentArr, index, ID);
            if(ID == studentArr[result].ID){ 
                printf("%d, %s, %s, %.2f\n", 
                studentArr[result].ID, 
                studentArr[result].firstName, 
                studentArr[result].lastName, 
                studentArr[result].GPA);
             
            }
    else {
        printf("This ID is not in the records\n");
    }
        }
    }
}
int searchStudentID(Student studentArr[], int index, int ID){
    int low = 0, high = index - 1;
   
    while (low <= high){
      int middle = low + (high - low)/2;
      if(ID == studentArr[middle].ID){
        return middle;
      }
      else if(ID < studentArr[middle].ID){
        high = middle - 1;
      }
        else{
            low = middle + 1;
        }

   }
   return -1;
}

int main(){
readingFile();
  return 0;
}