#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <bitset>
#include <algorithm>
#define int long long
using namespace std;

struct query
{
    int x, y, i;
} que[100005];

int c, n, m, d, qc;
bool SpecB = true;
int w[500005], k[505], nas[100005];
vector<int> a[505], t[505];
vector<pair<int, int> > e[600005];
int rt, dis[600005];
bitset<600005> vis;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
queue<pair<int, int> > bq;

bool cmp(query x, query y)
{
    return x.x < y.x;
}

void bfs()
{
    for (int i = 1; i <= n + m; i++)
        dis[i] = 4e18;
    vis.reset();
    vis[rt] = true;
    bq.push({0, rt});
    while (!bq.empty())
    {
        int u = bq.front().second;
        dis[u] = min(dis[u], bq.front().first);
        bq.pop();
        for (pair<int, int> i : e[u])
        {
            int v = i.first, w = i.second;
            if (!vis[v])
            {
                vis[v] = true;
                bq.push({dis[u] + w, v});
            }
        }
    }
}

void dijkstra()
{
    if (12 <= c && c <= 19 || SpecB)
        bfs();
    for (int i = 1; i <= n + m; i++)
        dis[i] = 4e18;
    vis.reset();
    dis[rt] = 0;
    q.push({dis[rt], rt});
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (pair<int, int> i : e[u])
        {
            int v = i.first, w = i.second;
            if (dis[v] > dis[u] + w)
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
    cin >> c >> n >> m >> d >> qc;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        a[i].resize(k[i] + 1);
        t[i].resize(k[i] + 1);
        for (int j = 1; j <= k[i]; j++)
        {
            cin >> a[i][j] >> t[i][j];
            if (t[i][j] != t[1][1])
                SpecB = false;
            e[m + i].push_back({a[i][j], t[i][j]});
            e[a[i][j]].push_back({m + i, t[i][j]});
        }
    }
    for (int i = 1; i <= qc; i++)
    {
        cin >> que[i].x >> que[i].y;
        que[i].i = i;
    }
    sort(que + 1, que + 1 + qc, cmp);
    rt = 0;
    for (int i = 1; i <= qc; i++)
    {
        if (rt == que[i].x)
        {
            nas[que[i].i] = dis[que[i].y] + w[que[i].x] + w[que[i].y];
            continue;
        }
        rt = que[i].x;
        dijkstra();
        nas[que[i].i] = dis[que[i].y] + w[que[i].x] + w[que[i].y];
    }
    for (int i = 1; i <= qc; i++)
        cout << nas[i] << '\n';
    return 0;
}