
#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
//测试点编号 地铁线路数 地铁站数 每个地铁最多被几条线路经过 出行计划数
int w[500005], k, a[505][500005], t[505][500005];
vector <pair <int, int> > vt[500005];
//vt存连接的地铁站与第几条线路
long long dis[500005];
//每一个从x走的最少步行距离
bool vis[500005];

void dfs(int u)
{
    for (auto j : vt[u])
    {
        int v = j.first, w = j.second;
        if (!vis[v])
        {
            vis[v] = 1;
            dis[v] = min(dis[u] + w, dis[v]);
            dfs(v);
        }
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> a[i][j] >> t[i][j];
        }
        if (k == 2)
        {
            vt[a[i][1]].push_back({a[i][2], t[i][1] + t[i][2]});
            vt[a[i][2]].push_back({a[i][1], t[i][1] + t[i][2]});
        }
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        for (int i = 0; i <= m; i++) dis[i] = 1e18, vis[i] = 0;
        dis[x] = 0;
        //vis[x] = 1;
        dfs(x);
        cout << dis[y] + w[x] + w[y] << "\n";
    }
    return 0;
}
/*
0 4 4 20 2
4 1 9 2
2 1 5 2 7
2 2 2 4 6
2 3 1 4 2
2 3 4 2 4
1 4
*/
