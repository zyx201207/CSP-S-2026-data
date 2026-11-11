#include <bits/stdc++.h>
#define int long long
using namespace std;

struct nnode
{
    int z, id, size;
};

struct node
{
    int z, id, size, cost;
};

int c, n, m;
int dis[505];
int disy[20005];
int ds[505];
int w[505];
vector<nnode> g[50505];
int ans[595][505];

void bfs(int s)
{
    queue<node> q;
    dis[s] = 0;
    for(nnode c : g[s])
    {
        q.push(node{c.z, s, c.size, c.size});
    }
    while(q.size())
    {
        node x = q.front();
        q.pop();
        if(x.id <= n)
        {
            ds[x.id] = min(ds[x.id], dis[x.id] + x.size);
        }
        //cout << x.id << ' ' << x.cost << ' ' << x.z << ' ' << x.size << "\n";
        for(nnode c : g[x.id])
        {
            int y = c.id;
            int z = c.z;
            int size = c.size;
            if(z != x.z)
            {
                if(y > n)
                {
                    if(x.cost + x.size + size < disy[y])
                    {
                        //cout << y << " ";
                        disy[y] = x.cost + x.size + size;
                        q.push(node{z, y, size, disy[y]});
                    }
                }
                if(dis[y] > x.cost + x.size + size)
                {
                    //cout << y << " ";
                    dis[y] = x.cost + x.size + size;
                    q.push(node{z, y, size, dis[y]});
                }
            }
            else
            {
                if(y > n)
                {
                    if(disy[y] > x.cost)
                    {
                        //cout << y << " ";
                        disy[y] = x.cost;
                        q.push(node{z, y, size, disy[y]});
                    }
                }
                else if(x.id > n)
                {
                    if(dis[y] > x.cost)
                    {
                        //cout << y << " ";
                        dis[y] = x.cost;
                        q.push(node{z, y, size, dis[y]});
                    }
                }
                else
                {
                    if(dis[y] > x.cost)
                    {
                        //cout << y << " ";
                        dis[y] = x.cost;
                        q.push(node{z, y, size, dis[y]});
                    }
                }
            }
        }
        //cout << "\n";
    }
}

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int d, q;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> m >> n >> d >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for(int i = 1; i <= m; i++)
    {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(nnode{i, n + i, b});
            g[n + i].push_back(nnode{i, a, b});
        }
    }
    for(int i = 1; i <= n; i++)
    {
        memset(disy, 0x3f, sizeof(disy));
        memset(dis, 0x3f, sizeof(dis));
        memset(ds, 0x3f, sizeof(ds));
        bfs(i);
        for(int j = 1; j <= n; j++)
        {
            ans[i][j] = ds[j];
        }
    }
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        //memset(dis, 0x3f, sizeof(dis));
        //memset(ds, 0x3f, sizeof(ds));
        //memset(disy, 0x3f, sizeof(disy));
        //bfs(x);
        cout << ans[x][y] + w[x] + w[y] << "\n";
    }
    return 0;
}