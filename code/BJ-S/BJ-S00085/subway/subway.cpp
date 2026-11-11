#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int, int>
#define pli pair<ll, int>
const int N = 505;
const int M = 5e5 + 5;
int c, n, m, d, q;
int w[N];
vector<pii> pass[M];
vector<pli> e[N];
ll dis[N][N];
void dijkstra(int s)
{
    priority_queue<pli, vector<pli>, greater<pli>> q;
    q.push({0ll, s});
    dis[s][s] = 0;
    while (!q.empty())
    {
        pli cur = q.top();
        int u = cur.second;
        ll d = cur.first;
        q.pop();
        if (d != dis[s][u]) continue;
        for (auto nxt : e[u])
        {
            int v = nxt.second;
            ll val = nxt.first;
            if (dis[s][v] > dis[s][u] + val)
            {
                dis[s][v] = dis[s][u] + val;
                q.push({dis[s][v], v});
            }
        }
    }
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++) cin >> w[i];
    for (int i = 1; i <= n; i ++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j ++)
        {
            int a, t;
            cin >> a >> t;
            pass[a].push_back({i, t});
        }
    }
    for (int u = 1; u <= m; u ++)
    {
        for (int i = 0; i < pass[u].size(); i ++)
        {
            for (int j = 0; j < pass[u].size(); j ++)
            {
                if (i == j) continue;
                int l1 = pass[u][i].first, l2 = pass[u][j].first;
                int t1 = pass[u][i].second, t2 = pass[u][j].second;
                e[l1].push_back({t1 + t2, l2});
                e[l2].push_back({t1 + t2, l1});
            }
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i ++)
        dijkstra(i);
    while (q --)
    {
        int u, v;
        cin >> u >> v;
        ll ans = LLONG_MAX;
        for (auto i : pass[u])
            for (auto j : pass[v])
                ans = min(ans, dis[i.first][j.first] + i.second + j.second);
        cout << ans + w[u] + w[v] << endl;
    }
    return 0;
}