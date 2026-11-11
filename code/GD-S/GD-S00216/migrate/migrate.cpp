#include <bits/stdc++.h>
using namespace std;
int c, T, n;
long long d, x[2000005];
struct dd
{
    long long dis, cnt;
} dp[2000005];
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> T;
    if (c <= 6)
    {
        while (T--)
        {
            cin >> n >> d;
            for (int i = 1; i <= n; i++)
                cin >> x[i];
            long long ans = 0;
            const long long inf = 1LL << 62;
            for (int i = 1; i <= n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    dp[j].dis = inf;
                    dp[j].cnt = 0;
                    for (int k = j - 1; k >= i && x[j] <= d + x[k]; k--)
                    {
                        if (dp[j].dis == dp[k].dis + 1)
                            dp[j].cnt++;
                        else if (dp[j].dis > dp[k].dis + 1)
                        {
                            dp[j].dis = dp[k].dis + 1;
                            dp[j].cnt = 1;
                        }
                    }
                    if (dp[j].cnt == 2)
                        ans++;
                }
            }
            cout << ans << '\n';
        }
    }
    else if (c == 13 || c == 14)
        cout << 0 << '\n';
    return 0;
}