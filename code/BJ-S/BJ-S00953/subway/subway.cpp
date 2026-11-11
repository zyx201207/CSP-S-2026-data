#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

long long c, n, m, d, q, w[500005], head[1000005], k, cnt = 0, cnte = 0, x, y, ans[100005], dis[1000005], vis[1000005], mul = 1;
struct edge
{
    long long v, to, nxt;
}e[2000005];
struct query
{
    long long id, u, v;
}r[100005];
struct dist
{
    long long id, v;
};
void add_edge(long long a, long long b, long long c)
{
    cnte++;
    e[cnte].v = c, e[cnte].to = b, e[cnte].nxt = head[a], head[a] = cnte;
    cnte++;
    e[cnte].v = c, e[cnte].to = a, e[cnte].nxt = head[b], head[b] = cnte;
}
bool cmp(query w, query z)
{
    if (w.u != z.u) return w.u < z.u;
    return w.v < z.v;
}
void dijkstra(long long u)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > tmp;
    for (int i = 1; i <= cnt; i++) dis[i] = 1e18;
    memset(vis, false, sizeof(vis));
    dis[u] = 0;
    tmp.push({0, u});
    while (!tmp.empty())
    {
        long long v1 = tmp.top().first, id = tmp.top().second;
        tmp.pop();
        if (vis[id]) continue;
        vis[id] = true;
        for (int now = head[id]; now; now = e[now].nxt)
        {
            if (dis[e[now].to] > dis[id] + e[now].v)
            {
                dis[e[now].to] = dis[id] + e[now].v;
                //cout << e[now].to << ' ' << dis[e[now].to] << '\n';
                tmp.push({dis[e[now].to], e[now].to});
            }
        }
    }
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    cnt = m;
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cnt++;
            cin >> x >> y;
            add_edge(cnt, x, y);
            if (j != 1) add_edge(cnt, cnt - 1, 0);
        }
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> x >> y;
        if (x <= y) r[i] = {i, x, y};
        else r[i] = {i, y, x};
    }
    sort(r + 1, r + q + 1, cmp);
    for (int i = 1; i <= q; i++)
    {
        if (r[i].u != r[i - 1].u) dijkstra(r[i].u);
        ans[r[i].id] = dis[r[i].v] + w[r[i].u] + w[r[i].v];
    }
    for (int i = 1; i <= q - 1; i++) cout << ans[i] << '\n';
    cout << ans[q];
    return 0;
}
