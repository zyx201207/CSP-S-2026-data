// Simply Lovely
// 100pts
#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <pair <int, int> > zh[500005];
int ed[505][505];
/*
1~n n+1~n+m
*/
int c, n, m, d, q;
int w[500005];
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld", w + i);
    }
    // int T;
    for (int i = 1; i <= n; i++)
    {
        int k;
        scanf("%lld", &k);
        for (int j = 1; j <= k; j++)
        {
            int a, t;
            scanf("%lld %lld", &a, &t);
            zh[a].emplace_back(i, t);
            // T = t;
        }
    }
        memset(ed, 0x3f, sizeof ed);
        for (int i = 1; i <= n; i++)
                ed[i][i] = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < zh[i].size(); j++)
            {
                for (int k = 0; k < zh[i].size(); k++)
                {
                    if (j == k)
                        continue;
                    int x = zh[i][j].first;
                    int y = zh[i][k].first;
                    int val = zh[i][j].second + zh[i][k].second;
                    ed[x][y] = ed[y][x] = (ed[x][y] > val ? val : ed[x][y]);
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    ed[k][j] = ed[j][k] = min(ed[j][k], ed[j][i] + ed[i][k]);
                }
            }
        }
        while (q--)
        {
            int x, y;
            scanf("%lld %lld", &x, &y);
            int ans = 0x3f3f3f3f3f3f3f3f;
            for (pair <int, int> i : zh[x])
            {
                for (pair <int, int> j : zh[y])
                {
                    ans = min(ans, ed[i.first][j.first] + i.second + j.second);
                }
            }
            printf("%lld\n", ans + w[x] + w[y]);
        }
        return 0;
}