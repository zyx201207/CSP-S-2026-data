#include <bits/stdc++.h>
using namespace std;

const long long maxn = 1e6+5;

int c,n,m,d,q;
int w[maxn];

int t[505][505];
int a[505][505];
int k[maxn];

struct node
{
    int v,w;
};
// vector<node> g[maxn];

vector<node> g[maxn];
set<int> s;


int nodes_cnt;

map<int,vector<int>> nodemap;

void init()
{
    cin >> c >> n >> m >> d >> q;

    // if(c == 0)
    // {
    //     cout << "32" << "\n" << "17" << endl;
    //     exit(0);
    // }

    for(int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }

    for(int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for(int j = 1; j <= 2 * k[i]; j++)
        {
            if(j & 1)
            {
                cin >> a[i][j / 2 + 1]; // 1 1 : a[1][1]
            }
            else
            {
                cin >> t[i][j / 2];
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 2; j <= k[i]; j++)
        {
            s.insert(a[i][j-1]);
            s.insert(a[i][j]);

            g[a[i][j-1]].push_back({a[i][j],t[i][j]});
            g[a[i][j]].push_back({a[i][j-1],t[i][j]});

            nodemap[a[i][j]].push_back(i);
            nodemap[a[i][j-1]].push_back(i);
        }
    }

    nodes_cnt = s.size();
}

int min_time = 0x3f3f3f3f;

int vis[maxn];

void dfs(int u,int start,int end,int time,int fa,int traffic)
{

    if(vis[u]) return;
    vis[u] = 1;

    if(u == fa)
    {
        // vis[u] = 0;
        return;
    }
    if(u == end)
    {
        // cout << "w: " << u << endl;
        // cout << endl;
        time += w[u];
        min_time = min(min_time,time);
        vis[u] = 0;
        return;
    }
    if(u == start)
    {
        // cout << "w: " << u << endl;
        time += w[u]; 
        time += t[u][u];
    }


    for(auto &e : g[u])
    {
        int v = e.v;
        int w = e.w;
        // if(v == fa) continue;

        // cout << "u v :" << t[u][v] << " " << endl;
        time += t[u][v];

        for(auto it : nodemap[v])
        {
            // cout << v << " ";
            // cout << it << endl;
            if(traffic == it)
            {
                dfs(v,start,end,time,u,traffic);
                // vis[u] = 0;
            }
            else
            {
                // cout << "u u : " <<  t[u][u] << " " << endl;
                time += (t[v][v]);
                dfs(v,start,end,time,u,it);
                // vis[u] = 0;
            }
        }
    }
    vis[u] = 0;
}

void work()
{
    while(q--)
    {
        memset(vis,0,sizeof(vis));
        int x,y;
        cin >> x >> y;
        for(auto i : nodemap[x])
        {
            // cout << i<< endl;
            dfs(x,x,y,0,-1,i);
        }
        cout << min_time << endl;
    }
}


int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    init();
    work();
    return 0;
}