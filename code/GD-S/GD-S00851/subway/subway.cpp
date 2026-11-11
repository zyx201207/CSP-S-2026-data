#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

struct edge
{
    int next, to;
    long long w;
};

bool flag[505], vis[500005];
int c, n, m, d, q, x, y, t1, cur, cnt, k[505], head[500005];
long long t2, ans, w[500005], dis[500005], res[1005][1005];
priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > que;
vector<pair<int, long long> > a[505];
vector<pair<pair<int, int>, int> > b[500005];
edge e[1000005];

inline void add(int u, int v, long long w)
{
    ++cur;
    e[cur] = {head[u], v, w};
    head[u] = cur;
    ++cur;
    e[cur] = {head[v], u, w};
    head[v] = cur;
}

inline void dijkstra(int s)
{
    memset(vis, false, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i < b[s].size(); ++i)
    {
        que.push(make_pair(a[b[s][i].first.first][b[s][i].first.second].second, b[s][i].second));
        dis[b[s][i].second] = a[b[s][i].first.first][b[s][i].first.second].second;
    }
    while (!que.empty())
    {
        t1 = que.top().second;
        que.pop();
        if (vis[t1])
        {
            continue;
        }
        vis[t1] = true;
        for (int i = head[t1]; i; i = e[i].next)
        {
            if (dis[t1] + e[i].w < dis[e[i].to])
            {
                dis[e[i].to] = dis[t1] + e[i].w;
                que.push(make_pair(dis[e[i].to], e[i].to));
            }
        }
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%lld", w + i);
        b[i].push_back(make_pair(make_pair(0, 0), 0));
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", k + i);
        a[i].push_back(make_pair(0, 0));
        for (int j = 1; j <= k[i]; ++j)
        {
            scanf("%d%lld", &t1, &t2);
            a[i].push_back(make_pair(t1, t2));
            ++cnt;
            b[t1].push_back(make_pair(make_pair(i, j), cnt));
        }
        for (int j = 2; j <= k[i]; ++j)
        {
            add(b[a[i][j].first].back().second, b[a[i][j - 1].first].back().second, 0);
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j < b[i].size(); ++j)
        {
            for (int k = j + 1; k < b[i].size(); ++k)
            {
                add(b[i][j].second, b[i][k].second, a[b[i][j].first.first][b[i][j].first.second].second + a[b[i][k].first.first][b[i][k].first.second].second);
            }
        }
    }
    memset(res, 0x3f, sizeof(res));
    while (q--)
    {
        scanf("%d%d", &x, &y);
        ans = 9e18;
        if (!flag[x])
        {
            dijkstra(x);
            for (int i = 1; i <= m; ++i)
            {
                for (int j = 1; j < b[i].size(); ++j)
                {
                    res[x][i] = min(res[x][i], dis[b[i][j].second] + a[b[i][j].first.first][b[i][j].first.second].second);
                }
            }
            flag[x] = true;
        }
        printf("%lld\n", res[x][y] + w[x] + w[y]);
    }
    return 0;
}