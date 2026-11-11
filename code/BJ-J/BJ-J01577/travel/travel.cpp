#include <iostream>
using namespace std;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    char n1, n2;
    int c1, c2, r1, r2;
    scanf("%d %d%c %d %d%c", &c1, &r1, &n1, &c2, &r2, &n2);
    //printf("%d %d%c %d %d%c\n", c1, r1, n1, c2, r2, n2);
    if (c1 == c2) {
        printf("1");
        if (r1 == r2) {
            printf("1");
            if ((n1 >= 'A' && n1 <= 'C' && n2 >= 'A' && n2 <= 'C') || (n1 >= 'D' && n1 <= 'F' && n2 >= 'D' && n2 <= 'F')) {
                printf("1");
                if (min(n1, n2) + 1 == max(n1, n2)) {
                    printf("1");
                } else {
                    printf("0");
                }
            } else {
                printf("00");
            }
        } else {
            printf("000");
            return 0;
        }
    } else {
        printf("0000");
        return 0;
    }
}
