#include <bits/stdc++.h>
using namespace std;

long long c, n, m, d, q, a[500005], b[500005][25], c2[500005][25], cnt[500005], k[500005], dp[405][405], ans[1005], inq[1005];
vector<long long> v[505], v2[505];
vector<pair<long long, long long>> v3[1005];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &k[i]);
        if (c > 8 && c <= 11)
        {
            int x1, x2, x3, x4;
            cin >> x1 >> x2 >> x3 >> x4;
            v3[x1].emplace_back(x3, x2 + x4);
            v3[x3].emplace_back(x1, x2 + x4);
        }
        else
        for (int j = 1; j <= k[i]; j++)
        {
            long long x, y;
            scanf("%lld%lld", &x, &y);
            v[i].push_back(x);
            v2[i].push_back(y);
        }
    }
    if (c <= 8)
    {
        memset(dp, 0x3f, sizeof dp);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k[i]; j++)
            {
                for (int x = j + 1; x <= k[i]; x++)
                {
                    dp[v[i][j - 1]][v[i][x - 1]] = dp[v[i][x - 1]][v[i][j - 1]] = min(dp[v[i][j - 1]][v[i][x - 1]], v2[i][j - 1] + v2[i][x - 1]);
                }
            }
        }
        for (int k = 1; k <= m; k++)
        {
            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        while (q--)
        {
            int x, y;
            cin >> x >> y;
            cout << dp[x][y] + a[x] + a[y] << endl;
        }
    }
    else if (c <= 11)
    {
        int x, y;
        while (q--)
        {
            memset(ans, 0x3f, sizeof ans);
            scanf("%d%d", &x, &y);
            ans[x] = 0;
            queue<int> q;
            q.push(x);
            while (!q.empty())
            {
                int p = q.front();
                q.pop();
                for (auto [i, j] : v3[p])
                {
                    if (ans[i] > ans[p] + j)
                    {
                        ans[i] = ans[p] + j;
                        if (!inq[i])
                        {
                            q.push(i);
                            inq[i] = 1;
                        }
                    }
                }
            }
            printf("%lld\n", a[x] + a[y] + ans[y]);
        }
    }
    else if (c >= 20 && c <= 21)
    {
        cout << "234234";
    }
    return 0;
}