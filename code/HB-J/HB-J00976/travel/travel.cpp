#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    int p1, l1;
    char c1;
    int p2, l2;
    char c2;
    cin >> p1 >> l1 >> c1 >> p2 >> l2 >> c2;

    if (p1 != p2) {
        printf("0000");
        return 0;
    }

    printf("1");

    if (l1 != l2) {
        printf("000");
        return 0;
    }

    printf("1");

    if (!((c1 <= 'C' && c2 <= 'C') || (c1 > 'C' && c2 > 'C'))) {
        printf("00");
        return 0;
    }

    printf("1");

    if (abs(c1 - c2) > 1) {
        printf("0");
        return 0;
    }

    printf("1");
    return 0;
}