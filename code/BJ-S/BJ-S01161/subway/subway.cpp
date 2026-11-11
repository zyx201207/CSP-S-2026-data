#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define int long long
const int N = 3e3 + 5;
const int N2 = 5e5 + 5;
const int M = 500 + 5;
const int inf = 3e18 + 7;
int _, m, n, d, q, tot, dis[N][N], w[N2];
int dist[N2];
bool vis[N], used[M];
vector<pii> e[N];
vector<int> e2[N2];
void dijkstra(int s, int dis[N])
{
    for(int i = 1; i <= tot; i++)   dis[i] = inf, vis[i] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    dis[s] = 0;
    while(!q.empty())
    {
        int u = q.top().second, W = q.top().first;
        q.pop();
        if(vis[u] || W != dis[u])   continue;
        vis[u] = 1;
        for(auto it : e[u])
        {
            int v = it.first, w = it.second;
            if(dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
}
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> _ >> m >> n >> d >> q;
    if(12 <= _ && _ <= 19)
    {
        int tot = n;
        for(int i = 1; i <= n; i++) cin >> w[i];
        int T = -1;
        for(int i = 1; i <= m; i++)
        {
            int ki;
            cin >> ki;
            tot++;
            for(int j = 1; j <= ki; j++)
            {
                int u, w;
                cin >> u >> w;
                T = w;
                e2[u].push_back(tot);
                e2[tot].push_back(u);
            }
        }
        while(q--)
        {
            int s, t;
            cin >> s >> t;
            queue<int> pq;
            for(int i = 1; i <= tot; i++) dist[i] = -1;
            pq.push(s);
            dist[s] = 0;
            while(!pq.empty())
            {
                int u = pq.front();
                pq.pop();
                for(auto v : e2[u])
                {
                    if(dist[v] != -1)   continue;
                    dist[v] = dist[u] + 1;
                    pq.push(v);
                }
            }
            cout << w[s] + w[t] + (dist[t] * T) << "\n" ;
        }
        return 0;
    }
    tot = n;
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i <= m; i++)
    {
        int ki;
        cin >> ki;
        tot++;
        for(int j = 1; j <= ki; j++)
        {
            int u, w;
            cin >> u >> w;
            e[u].push_back({tot, w});
            e[tot].push_back({u, w});
        }
    }
    if(tot <= q)
    {
        for(int i = 1; i <= n; i++) dijkstra(i, dis[i]);
        while(q--)
        {
            int s, t;
            cin >> s >> t;
            cout << w[s] + w[t] + dis[s][t] << "\n" ;
        }
        return 0;
    }
    while(q--)
    {
        int s, t;
        cin >> s >> t;
        dijkstra(s, dis[s]);
        cout << dis[s][t] + w[s] + w[t] << "\n" ;
    }
    return 0;
}
