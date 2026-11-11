#include <bits/stdc++.h>
using namespace std;

const int N = 300 + 10;

int a[N], dp[N][N], cnt[N][N];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, t;
    cin >> c >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        if (1 <= c && c <= 6)
        {
            for (int i = 1; i <= n; ++i)
                for (int j = i + 1; j <= n; ++j)
                {
                    if (a[j] - a[i] <= d)
                        dp[i][j] = 1, cnt[i][j] = 1;
                    else dp[i][j] = 1e9, cnt[i][j] = 0;
                }
            for (int k = 1; k <= n; ++k)
                for (int i = 1; i <= n; ++i)
                    for (int j = 1; j <= n; ++j)
                    {
                        if (dp[i][k] == 1e9 || dp[k][j] == 1e9) continue;
                        int t = dp[i][k] + dp[k][j];
                        if (t < dp[i][j])
                            dp[i][j] = t, cnt[i][j] = cnt[i][k] * cnt[k][j];
                        else if (t == dp[i][j])
                            cnt[i][j] += cnt[i][k] * cnt[k][j];
                    }
            int ans = 0;
            for (int i = 1; i <= n; ++i)
                for (int j = i + 1; j <= n; ++j)
                    if (cnt[i][j] == 2)
                        ans++;
            cout << ans << endl;
        }
        else if (c == 11 || c == 12)
        {
            int dd = a[2] - a[1];
            if (dd >= d)
            {
                cout << 0 << endl;
                continue;
            }
            int ans = n - d / dd * 2 + 1;
            cout << ans << endl;
        }
    }
    return 0;
}