#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5, M = 505;
const int inf = 1e18 + 7;
int id, m, n, mx, T;
struct node
{
    int id;
    int t;
};
int dis[M][M];
vector<node> who[N];
int out[N];
int tot, x, y;
// bool flg[N];
// vector<int> g[M];
// void dijkstra(int num)
// {
//     queue<int> q;
//     q.push(num);
//     memset(flg, 0, sizeof(flg));
//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();
//         if (flg[u]) continue;
//         flg[u] = 1;
//         for (auto v : g[u])
//             if (dis[num][u] + dis[u][v] <= dis[num][v])
//             {
//                 dis[num][v] = dis[num][u] + dis[u][v];
//                 q.push(v);
//             }
//     }
// }
signed main(){
    ios::sync_with_stdio(false);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> id >> m >> n >> mx >> T;
    for (int i = 1; i <= n; i ++)
        cin >> out[i];
    for (int i = 1; i <= m; i ++)
    {
        cin >> tot;
        for (int j = 1; j <= tot; j ++)
        {
            cin >> x >> y;
            who[x].push_back({i, y});
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= m; i ++) dis[i][i] = 0;
    for (int u = 1; u <= n; u ++)
    {
        for (auto i : who[u])
            for (auto j : who[u])
            {
                dis[i.id][j.id] = min(dis[i.id][j.id], i.t + j.t);
                dis[j.id][i.id] = dis[i.id][j.id];
            }
    }
    for (int k = 1; k <= m; k ++)
        for (int i = 1; i <= m; i ++)
            for (int j = i + 1; j <= m; j ++)
                if (i != k && j != k)
                {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                    dis[j][i] = dis[i][j];
                }
    // for (int i = 1; i <= m; i ++)
    //     for (int j = i + 1; j <= m; j ++)
    //         if (dis[i][j] != 0x3f3f3f3f)
    //         {
    //             g[i].push_back(j);
    //             g[j].push_back(i);
    //         }
    // for (int i = 1; i <= m; i ++)
    //     dijkstra(i);
    while (T --)
    {
        cin >> x >> y;
        int ans = inf;
        for (auto i : who[x])
            for (auto j : who[y])
                ans = min(ans, dis[i.id][j.id] + i.t + j.t);
        cout << ans + out[x] + out[y] << "\n";
    }

    return 0;
}