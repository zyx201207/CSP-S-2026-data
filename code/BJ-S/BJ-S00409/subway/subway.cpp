#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m, d, q, c, w[1010], k[510], dis[1010][1010], vis[1010][1010];
struct node
{
    int v, w;
};
vector<node>e[1010], a[510];
bool operator < (node a, node b)
{
    return a.w > b.w;
}
void dij(int x)
{
    priority_queue<node>q;
    q.push({x, 0});
    dis[x][x] = 0;
    while(q.size())
    {
        int u = q.top().v, ww = q.top().w;
        q.pop();
        if(vis[x][u])
        {
            continue;
        }
        vis[x][u] = 1;
        for(auto i : e[u])
        {
            int v = i.v, f = i.w;
            if(dis[x][v] > ww + f)
            {
                dis[x][v] = ww + f;
                q.push({v, dis[x][v]});
            }
        }
    }
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            dis[i][j] = 2e9;
        }
    }
    for(int i = 1; i <= m; ++i)
    {
        cin >> w[i];
    }
    for(int i = 1; i <= n; ++i)
    {
        cin >> k[i];
        for(int j = 1; j <= k[i]; ++j)
        {
            int x, y;
            cin >> x >> y;
            a[i].push_back({x, y});
        }
        for(int j = 0; j < k[i]; ++j)
        {
            for(int t = 0; t < j; ++t)
            {
                int v1 = a[i][j].v, w1 = a[i][j].w;
                int v2 = a[i][t].v, w2 = a[i][t].w;
                e[v1].push_back({v2, w1 + w2});
                e[v2].push_back({v1, w1 + w2});
            }
        }
    }
    if(q > m)
    {
        for(int i = 1; i <= m; ++i)
        {
            dij(i);
        }
        while(q--)
        {
            int xr, yr;
            cin >> xr >> yr;
            cout << w[xr] + w[yr] + dis[xr][yr] << endl;
        }
    }
    else
    {
        while(q--)
        {
            int xr, yr;
            cin >> xr >> yr;
            dij(xr);
            cout << w[xr] + w[yr] + dis[xr][yr] << endl;
        }
    }
    return 0;
}
