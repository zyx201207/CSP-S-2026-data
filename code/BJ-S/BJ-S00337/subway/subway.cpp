#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int c, n, m, q, d;
long long w[N];
long long dis[505][505];
// ll to[505][N];
vector<pair<int, long long>> sta[N];
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i ++)
    {
        scanf("%lld", w + i);
    }
    for (int i = 1; i <= n; i ++)
    {
        int k;
        scanf("%d", &k);
        for (int j = 1; j <= k; j ++)
        {
            int s;
            long long t;
            scanf("%d%lld", &s, &t);
            sta[s].push_back(make_pair(i, t));
        }
    }
    for (int i = 1; i <= m; i ++)
    {
        for (int j = 0; j < sta[i].size(); j ++)
        {
            for (int k = j + 1; k < sta[i].size(); k ++)
            {
                int u = sta[i][j].first;
                int v = sta[i][k].first;
                long long val = sta[i][j].second + sta[i][k].second;
                if (!dis[u][v])
                {
                    dis[u][v] = dis[v][u] = val;
                }
                else
                {
                    if (dis[u][v] < val) continue;
                    dis[u][v] = dis[v][u] = val;
                }
            }
        }
    }
    for (int k = 1; k <= n; k ++)
    {
        for (int i = 1; i <= n; i ++)
        {
            for (int j = 1; j <= n; j ++)
            {
                if (i == j) continue;
                if (!dis[i][k] || !dis[k][j]) continue;
                if (!dis[i][j]) dis[i][j] = dis[i][k] + dis[k][j];
                else dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
            }
        }
    }
    // for (int i = 1; i <= n; i ++)
    // {
    //     for (int j = i + 1; j <= n; j ++)
    //     {
    //         printf("dis[%d][%d] = %lld\n", i, j, dis[i][j]);
    //     }
    // }
    while (q --)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        long long res = LLONG_MAX;
        for (int i = 0; i < sta[x].size(); i ++)
        {
            for (int j = 0; j < sta[y].size(); j ++)
            {
                int u = sta[x][i].first;
                int v = sta[y][j].first;
                // printf("%d: %d-> %d: %d\n", x, u, y, v);
                if (!dis[u][v] && u != v) continue;
                res = min(res, dis[u][v] + sta[x][i].second + sta[y][j].second);
            }
        }
        res += w[x] + w[y];
        printf("%lld\n", res);
    }
    return 0;
}