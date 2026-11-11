#include <bits/stdc++.h>
using namespace std;

int a[500001];
long long dp[501][501];
vector<pair<int, int> > g[500001];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int n, m, q;
    scanf("%*d %d %d %*d %d", &n, &m, &q);
    for(int i = 1;i <= m;i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            dp[i][j] = 1000000000000000000ll;
        }
        dp[i][i] = 0;
    }
    for(int i = 1;i <= n;i++)
    {
        int x;
        scanf("%d", &x);
        while(x--)
        {
            int p, t;
            scanf("%d %d", &p, &t);
            g[p].emplace_back(i, t);
        }
    }
    for(int i = 1;i <= m;i++)
    {
        for(auto x : g[i])
        {
            for(auto y : g[i])
            {
                dp[x.first][y.first] = min(dp[x.first][y.first], (long long)(x.second + y.second));
            }
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            for(int k = 1;k <= n;k++)
            {
                dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
            }
        }
    }
    while(q--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        long long res = LONG_LONG_MAX;
        for(auto u : g[x])
        {
            for(auto v : g[y])
            {
                res = min(res, a[x] + u.second + dp[u.first][v.first] + v.second + a[y]);
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}
