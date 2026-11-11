#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define x first
#define y second
const int N = 1e3 + 10;
int a[N][N], t[N][N];
int w[N];
map<int, vector<PII> > g;
int c, n, m, d, q;
int id(int i, int j)
{
    return j * 1000 + i;
}
pair<int,int> fid(int x)
{
    int i = x % 1000;
    int j = x / 1000;
    return {i, j};
}
int dij(int x, int y)
{
    map<int,int> st;
    map<int,int> dist;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            dist[id(i,j)] = 1e18;
        }
    }
    dist[x] = 0;
    priority_queue<PII> q;
    q.push({0, x});
    while(q.size())
    {
        int u = q.top().y;
        int v = q.top().x * -1;
        if(v != dist[u]) continue;
        q.pop();
        for(int i = 0; i < g[u].size(); i++)
        {
            int k = g[u][i].x;
            int v = g[u][i].y;
            if(st[k]) continue;
            if(dist[k] > dist[u] + v)
            {
                dist[k] = dist[u] + v;
                q.push({-dist[k], k});
            }
        }
    }
    return dist[y];
}
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &d, &q);
    for(int i = 1; i <= m; i++) scanf("%lld", &w[i]);
    for(int i = 1; i <= n; i++)
    {
        int k; scanf("%lld", &k);
        for(int j = 1; j <= k; j++)
        {
            scanf("%lld %lld", &a[i][j], &t[i][j]);
            g[id(i,a[i][j])].push_back({id(0, a[i][j]), t[i][j]});
            g[id(0,a[i][j])].push_back({id(i, a[i][j]), t[i][j]});
            if(j > 1)
            {
                g[id(i,a[i][j])].push_back({id(i, a[i][j-1]), 0});
                g[id(i,a[i][j-1])].push_back({id(i, a[i][j]), 0});
            }
        }
    }
    /*for(int i = 0; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << i << ' ' << j << endl;
            for(int k = 0; k < g[id(i, j)].size(); k++)
            {
                PII _ = fid(g[id(i, j)][k].x);
                cout << _.x << ' ' << _.y << ' ' << g[id(i, j)][k].y << endl;
            }
        }
    }*/
    for(int i = 1; i <= q; i++)
    {
        int x, y;
        scanf("%lld %lld", &x, &y);
        cout << dij(id(0,x), id(0,y)) + w[x] + w[y] << '\n';
    }
    return 0;
}
