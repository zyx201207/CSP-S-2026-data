#include <bits/stdc++.h>
using namespace std;

long long m, a[500005];
int main()
{
    //freopen("crystal.in", "r", stdin);
    //freopen("crystal.out", "w", stdout);

    int n;
    cin >> n >> m;
    int dp[n + 1][m + 1];
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            dp[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            for(int k = i + 1; k <= n; k++)
            {
                dp[i][j] = dp[i][j - 1];
                if(a[k] - a[i] <= m)
                    dp[i][j] = max(dp[i][j], dp[i][j - (a[k] - a[i])] + 1);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;

    return 0;
}
