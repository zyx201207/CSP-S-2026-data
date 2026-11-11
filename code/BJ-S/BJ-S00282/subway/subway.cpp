#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cctype>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 5e5+5, K = 3e6 + 5;
ll rd()
{
    ll f = 1, c = getchar(), s = 0;
    for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
    for (; isdigit(c); c = getchar()) s = s * 10 + (c ^ 48);
    return s * f;
}
struct node
{
    ll v, w;
};
bool operator< (const node x, const node y)
{
    return x.w > y.w;
}
ll c, n, m, d, q, entry[N], ting[N], idx, xx, k, a, t, dis[K], vis[K], ss, tt;
vector<node> adj[K];
void dijkstra(ll s)
{
    priority_queue<node> pq;
    for (int i = 1; i <= idx; i++)
    {
        dis[i] = 1e18;
        vis[i] = 0;
    }
    dis[s] = 0;
    pq.push({s, dis[s]});
    while (!pq.empty())
    {
        node cur = pq.top();
        pq.pop();
        ll u = cur.v;
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto x : adj[u])
        {
            ll v = x.v, w = x.w;
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                pq.push({v, dis[v]});
            }
        }
    }
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = rd(), n = rd(), m = rd(), d = rd(), q = rd();
    for (int i = 1; i <= m; i++)
    {
        xx = rd();
        entry[i] = ++idx;
        ting[i] = ++idx;
        adj[entry[i]].push_back({ting[i], xx});
        adj[ting[i]].push_back({entry[i], xx});
    }
    for (int i = 1; i <= n; i++)
    {
        k = rd();
        idx++;
        for (int j = 1; j <= k; j++)
        {
            a = rd(), t = rd();
            adj[ting[a]].push_back({idx, t});
            adj[idx].push_back({ting[a], t});
        }
    }
    for (int i = 1; i <= q; i++)
    {
        ss = rd(), tt = rd();
        dijkstra(entry[ss]);
        cout << dis[entry[tt]] << "\n";
    }
    return 0;
}
