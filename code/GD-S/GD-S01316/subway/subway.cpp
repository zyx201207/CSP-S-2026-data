// #include <bits/stdc++.h>
// #define endl '\n'
// #define int long long
// using namespace std;
// int c, n, m, d, qq, x, y, dis[500005];
// struct STRUCT
// {
//     int v, w;
// };
// vector<STRUCT> g[500005];
// queue<STRUCT> q;
// void mian()
// {
//     memset(dis, 0x3f, sizeof(dis));
//     cin >> x >> y;
//     q.push({2 * m + x, 0});
//     dis[2 * m + x] = 0;
//     while (q.size())
//     {
//         int u = q.front().v, w = q.front().w;
//         q.pop();
//         for (int i = 0; i < g[u].size(); i++)
//         {
//             int v = g[u][i].v, w = g[u][i].w;
//             if (dis[v] > dis[u] + w)
//             {
//                 dis[v] = dis[u] + w;
//                 q.push({v, dis[v]});
//             }
//         }
//     }
//     cout << dis[2 * m + y] << endl;
// }
// /*
// i: 站台
// m + i：站厅
// 2 * m + i：站口
// */
// signed main()
// {
//     // freopen("subway.in", "r", stdin);
//     // freopen("subway.out", "w", stdout);
//     ios::sync_with_stdio(0);
//     cin.tie(0), cout.tie(0);
//     cin >> c >> n >> m >> d >> qq;
//     for (int w, i = 1; i <= m; i++)
//     {
//         cin >> w;
//         g[2 * m + i].push_back({m + i, w});
//         g[m + i].push_back({2 * m + i, w});
//     }
//     for (int u = 1, v, w, k, i = 1; i <= n; i++)
//     {
//         cin >> k >> v >> w;
//         g[m + v].push_back({v, w});
//         g[v].push_back({m + v, w});
//         u = v;
//         for (int j = 2; j <= k; j++)
//         {
//             cin >> v >> w;
//             g[u].push_back({v, 0});
//             g[v].push_back({u, 0});
//             g[m + v].push_back({v, w});
//             g[v].push_back({m + v, w});
//             u = v;
//         }
//     }
//     while (qq--)
//         mian();
// }

#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int c, n, m, d, qq, x, y, fau, fai, dis[500005];
struct STRUCT
{
    int v, w, f;
};
vector<STRUCT> g[500005];
queue<STRUCT> q;
void mian()
{
    memset(dis, 0x3f, sizeof(dis));
    cin >> x >> y;
    q.push({2 * m + x, 0, 0});
    dis[2 * m + x] = fau = fai = 0;
    while (q.size())
    {
        int u = q.front().v;
        q.pop();
        for (int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i].v, w = g[u][i].w;
            if (v <= m && g[u][i].f != g[fau][fai].f)
            {
                if (dis[v] > dis[u] + w + g[fau][fai].w)
                {
                    dis[v] = dis[u] + w + g[fau][fai].w;
                    q.push({v, dis[v], g[u][i].f});
                }
            }
            else
            {
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    q.push({v, dis[v], 0});
                }
            }
            fau = u, fai = i;
        }
    }
    cout << dis[2 * m + y] << endl;
}
/*
i: 站台
m + i：站厅
2 * m + i：站口
*/
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> qq;
    for (int w, i = 1; i <= m; i++)
    {
        cin >> w;
        g[2 * m + i].push_back({m + i, w, 0});
        g[m + i].push_back({2 * m + i, w, 0});
    }
    for (int u = 1, v, w, k, i = 1; i <= n; i++)
    {
        cin >> k >> v >> w;
        g[m + v].push_back({v, w, 0});
        g[v].push_back({m + v, w, 0});
        u = v;
        for (int j = 2; j <= k; j++)
        {
            cin >> v >> w;
            g[m + v].push_back({v, w, 0});
            g[v].push_back({m + v, w, 0});
            if (g[v].size() > 1)
            {
                g[u].push_back({v, g[v][m + v].w, i});
                g[v].push_back({u, g[v][m + v].w, i});
            }
            else
            {
                g[u].push_back({v, 0, i});
                g[v].push_back({u, 0, i});
            }
            u = v;
        }
    }
    while (qq--)
        mian();
}