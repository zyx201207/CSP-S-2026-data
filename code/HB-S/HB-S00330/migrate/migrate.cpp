#include <bits/stdc++.h>
using namespace std;
#define N 2000005
int c, t;
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while (t--)
    {
        int n, d, x[N];
        scanf("%d%d", &n, &d);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &x[i]);
        }
        int k = x[n] - x[n - 1], yyz = 0;
        for (int i = 1; i < n; i++)
        {
            if (x[i] + k == x[i + 1])
                yyz++;
        }
        if (yyz == n - 1)
        {
            if (d < k * 2 || d > k * n)
                printf("0\n");
            else
                printf("%d\n", n - (d / k * 2) + 1);
        }
        else
        {
            printf("%d", (x[1] + x[n]) / 2);
        }
    }
    return 0;
}
