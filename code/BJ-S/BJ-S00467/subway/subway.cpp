// 44ptss
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;
int _c, n, m, d;
ll w[500001];
int k[500001];
ll a[501][1001], t[501][1001];
int x[100001], y[100001];
struct edge
{
    int v;
    ll w;
};
vector<edge> g[500001];
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
ll dis[1001][1001];
bool vis[1001][1001];
void Dijkstra(int s)
{
    memset(dis[s], 0x7f, sizeof(dis[s]));
    dis[s][s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        int u = q.top().id;
        q.pop();
        if (vis[s][u]) continue;
        vis[s][u] = true;
        for (auto it: g[u])
        {
            int v = it.v; ll w = it.w;
            if (dis[s][v] > dis[s][u] + w)
            {
                dis[s][v] = dis[s][u] + w;
                q.push({dis[s][v], v});
            }
        }
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int q;
    cin >> _c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++)
        {
            cin >> a[i][j] >> t[i][j];
        }
        // cout << "第 " << i << " 条线路" << endl;
        for (int u = 1; u <= k[i]; u++)
        {
            for (int v = 1; v < u; v++)
            {
                g[a[i][u]].push_back({a[i][v], t[i][u] + t[i][v]});
                g[a[i][v]].push_back({a[i][u], t[i][u] + t[i][v]});
                // cout << a[i][u] << " " << a[i][v] << " " << t[i][u] + t[i][v] << endl;
            }
        }
    }
    // cout <<"\n\n\n\n\n";
    for (int i = 1; i <= m; i++)
        Dijkstra(i);

    for (int i = 1; i <= q; i++)
    {
        cin >> x[i] >> y[i];
        cout << w[x[i]] + dis[x[i]][y[i]] + w[y[i]] << endl;
    }
    return 0;
}