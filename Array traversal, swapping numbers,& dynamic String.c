#include <stdio.h>
#include <stdlib.h> // For malloc, free, realloc
#include <string.h> // For strcpy, strlen

// Function to swap two integers using pointers
void swap_integers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    // 1. Array Traversal using Pointers
    printf("--- Array Traversal ---\n");
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr_arr = arr; // Pointer to the first element of the array
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *ptr_arr); // Dereference the pointer to get the value
        ptr_arr++; // Move the pointer to the next element
    }
    printf("\n\n");

    // 2. Swapping Numbers using Pointers
    printf("--- Swapping Numbers ---\n");
    int num1 = 100, num2 = 200;
    printf("Before swap: num1 = %d, num2 = %d\n", num1, num2);
    swap_integers(&num1, &num2); // Pass addresses to the swap function
    printf("After swap: num1 = %d, num2 = %d\n\n", num1, num2);

    // 3. Dynamic String Manipulation using Pointers
    printf("--- Dynamic String Manipulation ---\n");
    char *dynamic_str;
    int initial_len = 15;

    // Allocate memory for the initial string
    dynamic_str = (char *)malloc(initial_len * sizeof(char));
    if (dynamic_str == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    strcpy(dynamic_str, "Hello");
    printf("Initial dynamic string: %s\n", dynamic_str);

    // Reallocate memory to extend the string
    int new_len = strlen(dynamic_str) + 10; // Add space for " World!" and null terminator
    dynamic_str = (char *)realloc(dynamic_str, new_len * sizeof(char));
    if (dynamic_str == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }
    strcat(dynamic_str, " World!");
    printf("Modified dynamic string: %s\n", dynamic_str);

    // Free the dynamically allocated memory
    free(dynamic_str);
    dynamic_str = NULL; // Good practice to set pointer to NULL after freeing

    return 0;
}