#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef long long ll;
int n, d;
int x[2000001];
struct edge
{
    int v;
    ll w;
};
vector<edge> g[2000001];
struct W
{
    ll dis;
    int id;
    friend bool operator > (W x, W y);
};
bool operator > (W x, W y)
{
    return x.dis > y.dis;
}
priority_queue<W, vector<W>, greater<W> > q;
ll dis[2000001];
int cnt[2000001];
bool vis[2000001];
void Dijkstra(int s)
{
    memset(dis, 0x7f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        int u = q.top().id;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto it: g[u])
        {
            int v = it.v; ll w = it.w;
            if (dis[v] == dis[u] + w)
                cnt[v] += cnt[u];
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                cnt[v] = 1;
                q.push({dis[v], v});
            }
            
        }
    }
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int _c, t;
    cin >> _c >> t;
    while (t--)
    {
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
            cin >> x[i];
        for (int i = 1; i <= n; i++)
        {
            for (int j = i+1; j <= n; j++)
            {
                if (x[j] - x[i] > d) break;
                g[i].push_back({j, 1});
                g[j].push_back({i, 1});
                // cout << i << " " << j << " " << x[j] - x[i] << endl;
            }
        }
        // cout << "\n";
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            Dijkstra(i);
            // cout << dis[i] << endl;
            for (int j = i+1; j <= n; j++)
                if (cnt[j] == 2) ans++;
            
            // for (int j = 1; j <= n; j++) cout << dis[j] << " ";
            // cout << endl;
        }
        cout << ans << endl;
        for (int i = 1; i <= n; i++) g[i].clear();
        // cout << "\n\n\n\n\n";
    }
    return 0;
}