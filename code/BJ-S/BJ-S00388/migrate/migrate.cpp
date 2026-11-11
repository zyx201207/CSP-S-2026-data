#include <bits/stdc++.h>
using namespace std;

int c, t;
int n, dp[2005][2005], cnt[2005][2005], ans;
long long d, x[2000005];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        ans = 0;
        memset(dp, 0x3f, sizeof(dp));
        memset(cnt, 0x3f, sizeof(cnt));
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> x[i];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (abs(x[j] - x[i]) <= d) dp[i][j] = 1, cnt[i][j] = 1;
            }
        }
        for (int k =  1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (dp[i][k] && dp[k][j])
                    {
                        if (dp[i][j] == dp[i][k] + dp[k][j]) cnt[i][j]++;
                        else if (dp[i][j] > dp[i][k] + dp[k][j]) dp[i][j] = dp[i][k] + dp[k][j], cnt[i][j] = 1;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (cnt[i][j] == 2) ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

