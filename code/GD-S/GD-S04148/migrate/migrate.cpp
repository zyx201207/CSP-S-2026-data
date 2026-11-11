#include <bits/stdc++.h>
#define MAXN 2000005
using namespace std;
long long a[MAXN], dp[MAXN], cnt[MAXN];
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c, t;
    cin >> c >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        bool check = true;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            memset(dp, 0x3f, sizeof(dp));
            memset(cnt, 0x3f, sizeof(cnt));
            dp[i] = 0;
            for (int j = i; j <= n; j++)
            {
                if (cnt[j] == 2)
                    ans++;
                for (int k = j + 1; k <= n && a[k] - a[j] <= d; k++)
                {
                    if (dp[j] + 1 < dp[k])
                    {
                        dp[k] = dp[j] + 1;
                        cnt[k] = 1;
                    }
                    else if (dp[j] + 1 == dp[k])
                        cnt[k]++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}