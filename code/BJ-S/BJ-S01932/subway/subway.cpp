#include <bits/stdc++.h>
using namespace std;

long long read()
{
    long long x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}

long long c, n, m, d, q, w[510000], k, a, b, ans = 1e15;
long long dis[510][510000];
bool vis[510000];
struct edge { long long y, len; };
struct node { long long x, dis; };
bool operator < (node x, node y) { return x.dis > y.dis; }
vector<edge> g[510000];
void dijkstra(long long dist[], long long s)
{
    priority_queue<node> q;
    memset(vis, 0, sizeof vis);
    dist[s] = 0;
    q.push({s, 0});
    while (!q.empty())
    {
        long long x = q.top().x;
        q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        for (edge i : g[x])
        {
            long long y = i.y, len = i.len;
            if (dist[y] > dist[x] + len)
            {
                dist[y] = dist[x] + len;
                q.push({y, dist[y]});
            }
        }
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    c = read(), n = read(), m = read(), d = read(), q = read();
    for (int i = 1; i <= m; i++) w[i] = read();
    for (int i = 1; i <= n; i++)
    {
        k = read();
        for (int j = 1; j <= k; j++)
        {
            a = read(), b = read();
            g[i].push_back({a + 500, b});
            g[a + 500].push_back({i, b});
        }
    }
    for (int i = 1; i <= 500; i++)
    {
        for (int j = 1; j <= 500 + m; j++)
        {
            dis[i][j] = 1e15;
        }
    }
    for (int i = 1; i <= 500; i++)
    {
        dijkstra(dis[i], i);
    }
    while (q--)
    {
        a = read(), b = read();
        ans = 1e15;
        for (int i = 1; i <= 500; i++)
        {
            ans = min(ans, dis[i][500 + a] + dis[i][500 + b]);
        }
        printf("%lld\n", w[a] + w[b] + ans);
    }
    return 0;
}
