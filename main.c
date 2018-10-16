//Rodrigo Perez Solis
//A01411278
//In this program we will ask the user to introduce the amount of numbers he want and we will seek for the unique numbers
// to finally show the user those unique numbers.

#include <stdio.h>
#include <stdlib.h>

// comparing function
int Compare(const void * a, const void * b) {
    return (*(int *) a - *(int *) b);
}

int main() {
    // we declare the variables
    int num;
    int r = 0;
    int count = 0;
    int uniqnumcount = 0;

    printf("Pleas tell me how many numbers would you like to enter?");
    scanf("%d", &num);

    // array declaration
    int numbers[num];
    int unique[num];

    for(int i = 0; i < num; i++){
        unique[i] = '\0';
    }

    // Storing of the values.
    for(int i = 0; i < num; i++){
        printf("%d:", i+1);
        scanf("%d", &numbers[i]);
    }

    // Sorting function.
    qsort(numbers, num, sizeof(int), Compare);


    //here we seek for the numbers that repeat and tell the user the unique ones
    for(int i = 0; i < num; i+=count+1){
        count = 0;
        for(int j = i + 1; j < num; j++){
            if(numbers[i] == numbers[j]){
                count++;
            }
        }
        // If a value is unique we store it here
        if(count == 0){
            unique[r] = numbers[i];
            r++;
        }
    }

    // we tell the user which are the unique numbers
    printf("The unique numbers are: ");
    for(int i = 0; i < num; i++){

        if(unique[i] == '\0'){
            break;
        }
        printf("%d ", unique[i]);
        uniqnumcount++;
    }

    // If there was not any unique element, the program prints that
    // there were none.
    if(uniqnumcount == 0){
        printf("we dont have a unique number.");
    }

    return 0;
}








