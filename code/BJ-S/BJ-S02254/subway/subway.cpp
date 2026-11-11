#include<bits/stdc++.h>
#define int long long
using namespace std;

int c, n, m, d, q;
int w[500005];
int T[500005];
int dp[505][505];
//pts 15
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = 1e18;
            if (i == j) dp[i][j] = 0;
            //cout << dp[i][j] << ' ';
        }
        //cout << endl;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        int a1, t1;
        cin >> a1 >> t1;
        for (int j = 2; j <= k; j++)
        {
            int a, t;
            cin >> a >> t;
            T[a] = t;
            dp[a][a1] = min(dp[a][a1], t + t1);
            dp[a1][a] = min(dp[a1][a], t + t1);
            a1 = a;
            t1 = t;
        }
    }

    for (int k = 1; k <= m; k++)
    {
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (dp[i][k] == 1e18 || dp[k][j] == 1e18)
                {
                    continue;
                }
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << dp[x][y] + w[x] + w[y] << endl;
    }
}
