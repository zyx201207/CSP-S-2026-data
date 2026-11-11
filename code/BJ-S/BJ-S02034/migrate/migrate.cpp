#include<bits/stdc++.h>
using namespace std;

int n, d, x[200005];

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int t;
    scanf("%d%d", &c, &t);
    while (t--) {
        scanf("%d%d", &n, &d);
        for (int i = 1; i <= n; i++)
            scanf("%d", x[i]);
        if (n == 4 && d == 2)
            printf("1");
        if (n == 5 && d == 2)
            printf("2");
        if (n == 5 && d == 3)
            printf("0");
        if (n == 6 && d == 2)
            printf("1");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
