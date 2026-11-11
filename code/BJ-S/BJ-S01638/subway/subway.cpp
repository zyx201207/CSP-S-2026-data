#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1000 + 10;
const int N = 500 + 10;
const int inf = 1e17;

int c, n, m, d, q, w[M], k[N], dis[M][3 * M], vis[3 * M], cur;
struct Edge { int v, w; };
vector<Edge> g[3 * M];
void add(int u, int v, int w) { g[u].push_back(Edge{v, w}); }
struct Node 
{ 
    int id, x; 
    bool operator > (const Node &b) const
    {
        return x > b.x;
    }   
};

void dijkstra(int st)
{
    priority_queue<Node, vector<Node>, greater<Node>> q;
    q.push(Node{st, 0});
    for (int i = 1; i <= cur; ++i) dis[st][i] = inf, vis[i] = 0;
    dis[st][st] = 0;
    while (!q.empty())
    {
        int u = q.top().id;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (Edge tmp : g[u])
        {
            int v = tmp.v, w = tmp.w;
            if (dis[st][u] + w < dis[st][v])
            {
                dis[st][v] = dis[st][u] + w;
                if (!vis[v]) q.push(Node{v, dis[st][v]});
            }
        }
    }
}

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    cur = m;
    for (int i = 1; i <= m; ++i) cin >> w[i];
    for (int i = 1; i <= n; ++i)
    {
        cin >> k[i];
        int fir = 0;
        for (int j = 1; j <= k[i]; ++j)
        {
            int a, t;
            cin >> a >> t;
            cur++;
            // cout << cur << endl;
            if (j == 1) fir = cur;
            add(a, cur, t);
            add(cur, a, t);
            // cout << a << "<->" << cur << ' ' << t << endl;
            if (j > 1)
            {
                add(cur, cur - 1, 0), add(cur - 1, cur, 0);
                // cout << cur << "<->" << cur - 1 << ' ' << 0 << endl;
            }
            if (j == k[i])
            {
                add(cur, fir, 0), add(fir, cur, 0);
                // cout << cur << "<->" << fir << ' ' << 0 << endl;
            }
        }
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        dijkstra(x);
        cout << dis[x][y] + w[x] + w[y] << "\n";
    }
    return 0;
}