#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
typedef pair < int, int > PII;
const int N = 505;
int c, n, m, d, q;
long long Walk[500005];
long long G[N][N], dist[N][N];
bool vis[N];
vector < pair < int, long long > > ygg[500005];
// void dijkstra(int st)
// {
//     priority_queue < pair < long long, int >, vector < pair < long long, int > >, greater < pair < long long, int > > > q;
//     for(int i = 1; i <= n; i++)dist[st][i] = LLONG_MAX;
//     for(int i = 1; i <= n; i++)vis[i] = 0;
//     dist[st][st] = 0;
//     q.push({0, st});
//     while(!q.empty())
//     {
//         auto cur = q.top();
//         q.pop();
//         int u = cur.sec;
//         if(vis[u])continue;
//         vis[u] = 1;
//         for(int v = 1; v <= n; v++)
//         {
//             if(G[u][v] == LLONG_MAX || u == v)continue;
//             if(dist[st][u] + G[u][v] < dist[st][v] && !vis[v])
//             {
//                 dist[st][v] = dist[st][u] + G[u][v];
//                 q.push({dist[st][v], v});
//             }
//         }
//     }
// }
void dijkstra(int st)
{
    for(int i = 1; i <= n; i++)dist[st][i] = LLONG_MAX;
    for(int i = 1; i <= n; i++)vis[i] = 0;
    dist[st][st] = 0;
    for(int temp = 1; temp <= n; temp++)
    {
        long long u, minn = LLONG_MAX;
        for(int i = 1; i <= n; i++)
        {
            if(vis[i])continue;
            if(minn > dist[st][i])
            {
                u = i;
                minn = dist[st][i];
            }
        }
        vis[u] = 1;
        for(int v = 1; v <= n; v++)
        {
            if(G[u][v] == LLONG_MAX || u == v || vis[v])continue;
            if(dist[st][u] + G[u][v] < dist[st][v])dist[st][v] = dist[st][u] + G[u][v];
        }
    }
}
void solve()
{
    int u, v;
    cin >> u >> v;
    int sizu = (int)ygg[u].size(), sizv = (int)ygg[v].size();
    long long ans = LLONG_MAX;
    for(int i = 0; i < sizu; i++)for(int j = 0; j < sizv; j++)ans = min(ans, ygg[u][i].sec + dist[ygg[u][i].fir][ygg[v][j].fir] + ygg[v][j].sec + Walk[u] + Walk[v]);
    cout << ans << "\n";
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= n; i++)for(int j = 1; j <= n; j++)G[i][j] = LLONG_MAX;
    for(int i = 1; i <= m; i++)cin >> Walk[i];
    for(int i = 1; i <= n; i++)
    {
        int pls;
        cin >> pls;
        for(int j = 1; j <= pls; j++)
        {
            int a, t;
            cin >> a >> t;
            ygg[a].push_back({i, t});
        }
    }
    for(int a = 1; a <= m; a++)
    {
        int siz = (int)ygg[a].size();
        for(int j = 0; j < siz; j++)for(int k = 0; k < siz; k++)G[ygg[a][j].fir][ygg[a][k].fir] = min(G[ygg[a][j].fir][ygg[a][k].fir], ygg[a][j].sec + ygg[a][k].sec);
    }
    for(int i = 1; i <= n; i++)G[i][i] = 0;
    for(int i = 1; i <= n; i++)dijkstra(i);
    while(q--)solve();
    return 0;
}
/*
啥题还考不堆优化的 Dijkstra，我都没背！！！！！！！！！！！！！！！
*/