#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
    int x, y, w;
    bool operator < (const node &b)
    const {
        return w > b.w;
    }
};

bool vis[222][444];
vector<node> g[444];
priority_queue<node> pq;
int w[444], k[222], a[222][444], t[222][444], dis[222][444];

void dij(int s)
{
    memset(vis, false, sizeof(vis));
    memset(dis, 0x7f, sizeof(dis));
    for (auto v : g[s])
    {
        pq.push(v);
        dis[v.x][v.y] = v.w;
    }
    while (!pq.empty())
    {
        int x = pq.top().x, y = pq.top().y;
        pq.pop();
        if (vis[x][y])
        {
            continue;
        }
        vis[x][y] = true;
        for (auto v : g[a[x][y]])
        {
            if (dis[v.x][v.y] > dis[x][y] + v.w + t[x][y])
            {
                pq.push({v.x, v.y, dis[x][y] + v.w + t[x][y]});
                dis[v.x][v.y] = dis[x][y] + v.w + t[x][y];
            }
        }
        for (int j = 1; j <= k[x]; j++)
        {
            if (dis[x][j] > dis[x][y])
            {
                pq.push({x, j, dis[x][y]});
                dis[x][j] = dis[x][y];
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
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++)
        {
            cin >> a[i][j] >> t[i][j];
            g[a[i][j]].push_back({i, j, t[i][j]});
        }
    }
    while (q--)
    {
        int s, t;
        cin >> s >> t;
        dij(s);
        int ans = 1e18;
        for (auto v : g[t])
        {
            ans = min(ans, dis[v.x][v.y] + v.w);
        }
        cout << ans + w[s] + w[t] << '\n';
    }
    return 0;
}
