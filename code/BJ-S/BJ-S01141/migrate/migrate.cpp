#include <bits/stdc++.h>
using namespace std;

long long a[2000001], dp[2][2000001];
int r[2000001];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int t;
    scanf("%*d %d", &t);
    while(t--)
    {
        int n;
        long long d;
        scanf("%d %lld", &n, &d);
        for(int i = 1;i <= n;i++)
        {
            scanf("%lld", &a[i]);
        }
        for(int i = n, j = n;i >= 1;i--)
        {
            while(j > i && a[j] - a[i] > d)
            {
                j--;
            }
            r[i] = j;
        }
        for(int i = n;i >= 1;i--)
        {
            if(r[i] != max(i, r[i - 1]))
            {
                dp[1][i] = r[i] - max(i, r[i - 1]) + dp[1][r[i]];
            }
            else
            {
                dp[1][i] = 0;
            }
        }
        for(int i = n;i >= 2;i--)
        {
            if(r[i] != i)
            {
                const int lf = max(i, r[i - 2]), rt = max(i, r[i - 1]), lim = r[i];
                dp[0][i] = rt - lf;
                if(rt == lim && rt != lf)
                {
                    dp[0][i] += dp[1][lim];
                }
                else if(rt <= lim - 2 || rt == i)
                {
                    dp[0][i] += dp[0][lim];
                }
            }
            else
            {
                dp[0][i] = 0;
            }
        }
        long long res = 0;
        for(int i = n;i >= 1;i--)
        {
            if(r[i] != i)
            {
                res += dp[0][r[i]];
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}
