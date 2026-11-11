#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int c, n, m, D, q, w[500010], k[510], a[510][500010], t[510][500010], x[100010], y[100010];
int c1 = 0, dis[500010], ans = 2e9, cc[500010], xian[500010], zhan[510][5010];
vector <int> g[500010], d[500010];
bool vis[510], flag = false, vi[510][5010];

/*void add(int x, int y, int z)
{
    to[++cntc] = y;
    ww[cntc] = z;
    nxt[cntc] = head[x];
    head[x] = cntc;
}*/

struct node
{
    int x, k;
    bool operator < (const node & b) const
    {
        return k < b.k;
    }
};

int dijstra(int s, int t)
{
    priority_queue <node> q;
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    dis[s] = 0;
    q.push({s, 0});
    while (q.size())
    {
        int x = q.top().x;
        q.pop();
        if (x == t) return dis[t];
        //if (vis[x]) continue;
        vis[x] = true;
        for (int i = 0; i < g[x].size(); i++)
        {
            int y = g[x][i];
            if (dis[y] > dis[x] + d[x][i])
            {
                dis[y] = dis[x] + d[x][i];
                if (!vis[y])
                {
                    vis[y] = true;
                    q.push({y, dis[y]});
                }
            }
        }
    }
}

void dfs(int step, int r, int xianlu, int sum)
{
    if (step == r)
    {
        ans = min(ans, sum);
        return ;
    }
    for (int i = 1; i <= cc[step]; i++)
    {
        if (xian[i] == xianlu) continue;
        if (vi[xianlu][step]) continue;
        vi[i][step] = true;
        dfs(step, r, xian[i], sum + t[xianlu][zhan[xianlu][step]] + t[i][zhan[i][step]]);
        vi[i][step] = false;
    }
    for (int i = 1; i <= k[xianlu]; i++)
    {
        if (a[xianlu][i] == step) continue;
        if (vi[xianlu][step]) continue;
        vi[xianlu][step] = true;
        dfs(a[xianlu][i], r, xianlu, sum);
        vi[xianlu][step] = false;
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> D >> q;
    for (int i = 1; i <= m; i++) scanf("%d", &w[i]);
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        if (k[i] > 2) c1 = 1;
        for (int j = 1; j <= k[i]; j++)
        {
            scanf("%d%d", &a[i][j], &t[i][j]);
            //cf[i][a[i][j]] = true;
            xian[++cc[a[i][j]]] = i;
            zhan[i][a[i][j]] = j;
        }
    }
    if (c1 == 0)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 2; j <= k[i]; j++)
            {
                //add(a[i][j - 1], a[i][j], t[i][j - 1] + t[i][j]);
                //add(a[i][j], a[i][j - 1], t[i][j - 1] + t[i][j]);
                g[a[i][j - 1]].push_back(a[i][j]);
                g[a[i][j]].push_back(a[i][j - 1]);
                d[a[i][j - 1]].push_back(t[i][j - 1] + t[i][j]);
                d[a[i][j]].push_back(t[i][j - 1] + t[i][j]);
            }
        for (int i = 1; i <= q; i++)
        {
            scanf("%d%d", &x[i], &y[i]);
            //dijstra(x[i], y[i]);
            printf("%d\n", dijstra(x[i], y[i]) + w[x[i]] + w[y[i]]);
        }
        return 0;
    }
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
        ans = 2e9;
        for (int j = 1; j <= cc[x[i]]; j++)
            dfs(x[i], y[i], xian[j], t[xian[j]][zhan[xian[j]][x[i]]]);
        printf("%d\n", ans + w[x[i]] + w[y[i]]);
    }
    return 0;
}
