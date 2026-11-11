#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 5e5 + 505, inf = 1e18;
int c, n, m, d, q, T, W[M], dis[M], dist[M], vis[M];
vector<pair<int, int> > G[M];
void dijkstra(int x)
{
    for (int i = 1; i <= n + m; i++) dis[i] = inf;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    dis[x] = 0;
    pq.push({0, x});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dis[u]) continue;
        for (auto [v, w] : G[u])
        {
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}
void bfs(int x)
{
    for (int i = 1; i <= n + m; i++) dist[i] = inf, vis[i] = 0;
    queue<int> q;
    q.push(x);
    dist[x] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 1;
        for (auto [v, w] : G[u])
        {
            if (vis[v]) continue;
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> W[i];
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int a, t;
            cin >> a >> t;
            T = t;
            G[a].push_back({m + i, t});
            G[m + i].push_back({a, t});
        }
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (12 <= c && c <= 19)
        {
            bfs(x);
            cout << W[x] + W[y] + dist[y] * T << '\n';
        }
        else
        {
            dijkstra(x);
            cout << W[x] + W[y] + dis[y] << '\n';
        }
    }
    return 0;
}
