#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
int dp[10000][10000];
int a[200005];

signed main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        dp[i][1] = max(dp[i - 1][1], a[i]);
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 2; j <= min(i, m); j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] & a[i]);
        }
    }

    printf("%lld", dp[n][m]);

    return 0;
}
