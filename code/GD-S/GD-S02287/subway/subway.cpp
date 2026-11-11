// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <random>
// #include <ctime>
// using namespace std;

// using ll = long long;

// mt19937_64 rnd(time(0));

// const int N = 500, INF = 1e9;

// struct Edge
// {
//     int v, w, id;
// };
// struct Dist
// {
//     int w, id1, id2, i1, i2;
// };

// int main()
// {
//     freopen("subway.in", "r", stdin);
//     freopen("subway.out", "w", stdout);
//     int c, n, m, d, q;
//     scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);

//     vector<int> w(m);
//     for (int i = 0; i < m; ++i)
//     {
//         scanf("%d", &w[i]);
//     }

//     vector<int> k(n);
//     vector<vector<int>> a(n), t(n);
//     for (int i = 0; i < n; ++i)
//     {
//         scanf("%d", &k[i]);
//         a[i].resize(k[i]);
//         t[i].resize(k[i]);
//         for (int j = 0; j < k[i]; ++j)
//         {
//             scanf("%d%d", &a[i][j], &t[i][j]);
//         }
//     }
//     vector<vector<Dist>> dis(m + 1, vector<Dist>(m + 1, {INF, 0, 0, 0, 0}));
//     for (int i = 0; i < n; ++i)
//     {
//         for (int j = 0; j < k[i] - 1; ++j)
//         {
//             dis[a[i][j]][a[i][j + 1]] = {0, i, i, j, j + 1};
//             dis[a[i][j + 1]][a[i][j]] = {0, i, i, j + 1, j};
//         }
//     }
//     for (int k = 1; k <= m; ++k)
//     {
//         for (int i = 1; i <= m; ++i)
//         {
//             for (int j = 1; j <= m; ++j)
//             {
//                 int cost1 = dis[i][k].w + dis[k][j].w;
//                 if (dis[i][k].id2 == dis[k][j].id1 && cost1 < dis[i][j].w)
//                 {
//                     dis[i][j] = {cost1, dis[i][k].id1, dis[k][j].id2, dis[i][k].i1, dis[k][j].i2};
//                 }

//                 int cost2 = dis[i][k].w + t[dis[i][k].id2][dis[i][k].i2] + t[dis[k][j].id1][dis[k][j].i1] + dis[k][j].w;
//                 if (dis[i][k].id2 != dis[k][j].id1 && cost2 < dis[i][j].w)
//                 {
//                     dis[i][j] = {cost2, dis[i][k].id1, dis[k][j].id2, dis[i][k].i1, dis[k][j].i2};
//                 }
//             }
//         }
//     }

//     while (q--)
//     {
//         int x, y;
//         scanf("%d%d", &x, &y);

//         cout << w[x - 1] + dis[x][y].w + w[y - 1] + t[dis[x][y].id1][dis[x][y].i1] + t[dis[x][y].id2][dis[x][y].i2] << "\n";
//     }
// }
// 666神了m看成n是地铁站数量
// dis[n][n]换成地铁路线。每个q最多20次找起始u（第几个路线）

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

const int N = 500;
const ll INF = 1e18;

struct Edge
{
    int i, j;
};

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);

    vector<int> w(m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &w[i]);
    }

    vector<int> k(n);
    vector<vector<int>> a(n), t(n);
    vector<vector<Edge>> g(m + 1);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &k[i]);
        a[i].resize(k[i]);
        t[i].resize(k[i]);
        for (int j = 0; j < k[i]; ++j)
        {
            scanf("%d%d", &a[i][j], &t[i][j]);
            // g[a[i][j]].emplace_back(i, j);
            g[a[i][j]].push_back({i, j});
        }
    }
    vector<vector<ll>> dis(n + 1, vector<ll>(n + 1, INF));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k[i]; ++j)
        {
            // for (auto [l, p] : g[a[i][j]])
            for (Edge x : g[a[i][j]])
            {
                // if (l == i)
                if (x.i == i)
                {
                    continue;
                }

                // dis[i][l] = t[i][j] + t[l][p];
                dis[i][x.i] = t[i][j] + t[x.i][x.j];
            }
        }
        dis[i][i] = 0;
    }
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    while (q--)
    {
        int x, y;
        scanf("%d%d", &x, &y);

        ll ans = INF;
        // for (auto &[i, j] : g[x])
        // {
        //     for (auto &[l, p] : g[y])
        for (Edge c : g[x])
        {
            for (Edge b : g[y])
            {
                // ans = min(dis[i][l] + w[i] + w[l] + t[i][j] + t[l][p], ans);
                ans = min(dis[c.i][b.i] + w[a[c.i][c.j] - 1] + w[a[b.i][b.j] - 1] + t[c.i][c.j] + t[b.i][b.j], ans);

                // printf("[%d][%d] %lld + %d + %d + %d + %d\n", c.i, b.i, dis[c.i][b.i], w[a[c.i][c.j] - 1], w[a[b.i][b.j] - 1], t[c.i][c.i], t[b.i][b.j]);
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
