#include <stdio.h>

struct vehicle {
    char brand[50];
    char owner_name[50];
    int year;
    float price;
};

int main()
{
    struct vehicle T[50];
    int n, i, j, imax;

    do {
        printf("Enter the number of vehicles (max: 50): ");
        scanf("%d", &n);
    } while (n < 1 || n > 50);

    for (i = 0; i < n; i++) {
        fflush(stdin);
        printf("\nVehicle (%d):\n", i + 1);

        printf("Enter the brand: ");
        gets(T[i].brand);

        printf("Enter the owner's name: ");
        gets(T[i].owner_name);

        printf("Enter the year of registration: ");
        scanf("%d", &T[i].year);

        printf("Enter the price: ");
        scanf("%f", &T[i].price);
    }

    printf("\nVehicle List:\n");
    for (i = 0; i < n; i++) {
        printf("\n* %s - %s - %d - %.2f",
               T[i].brand,
               T[i].owner_name,
               T[i].year,
               T[i].price);
    }

  
    for (imax = 0, i = 1; i < n; i++) {
        if (T[i].price > T[imax].price) {
            imax = i;
        }
    }

    printf("\nOwner of the most expensive vehicle: %s",
           T[imax].owner_name);

    for (i = 0, j = 0; i < n; i++) {
        if (T[i].year >= 2020) {
            T[j] = T[i];
            j++;
        }
    }

    n = j;

    printf("\nUpdated Vehicle List:\n");
    for (i = 0; i < n; i++) {
        printf("\n* %s - %s - %d - %.2f",
               T[i].brand,
               T[i].owner_name,
               T[i].year,
               T[i].price);
    }
    return 0;
}