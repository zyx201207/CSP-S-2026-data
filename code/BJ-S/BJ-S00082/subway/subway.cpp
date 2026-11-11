#include<bits/stdc++.h>
#define f first
#define se second
#define int long long
#define inf 0x7fffffff
#define pii pair<int,int>
using namespace std;
int c,n,m,d,q,w[500001],k[501],x,y,dis[500001],vis[500001];
vector<pii> vec[500001],e[510];
vector<int> a[501],t[501];
map<pii,int> p;
int dijkstra()
{
    for(int i = 1;i <= m;i++) dis[i] = inf,vis[i] = 0;
    priority_queue<pii,vector<pii>,greater<pii> > q;
    q.push({w[x],x});
    dis[x] = w[x];
    while(!q.empty())
    {
        int u = q.top().se,v = q.top().f;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = 0;i < vec[u].size();i++) for(int j = 0;j < k[vec[u][i].f];j++)
        {
            if(dis[a[vec[u][i].f][j]] > dis[u] + t[vec[u][i].f][vec[u][i].se] + t[vec[u][i].f][j])
            {
                dis[a[vec[u][i].f][j]] = dis[u] + t[vec[u][i].f][vec[u][i].se] + t[vec[u][i].f][j];
                q.push({dis[a[vec[u][i].f][j]],a[vec[u][i].f][j]});
                //cout << u << ' ' << a[vec[u][i].f][j] << ' ' << dis[u] << ' ';
                //cout << t[vec[u][i].f][u] << ' ' << t[vec[u][i].f][a[vec[u][i].f][j]] << endl;
            }
        }
    }
    //for(int i = 1;i <= m;i++) cout << dis[i] << endl;
    return dis[y] + w[y];
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1;i <= n;i++)
    {
        cin >> k[i];
        for(int j = 1,aa,tt;j <= k[i];j++)
        {
            cin >> aa >> tt;
            a[i].push_back(aa);
            t[i].push_back(tt);
            vec[aa].push_back({i,j - 1});
            p[{i,aa}] = 1;
        }
    }
    //for(int i = 1;i <= m;i++) for(int j = 0;j < vec[i].size();j++) cout << vec[i][j].f << ' ' << vec[i][j].se << endl;
    while(q--)
    {
        cin >> x >> y;
        cout << dijkstra() << endl;
    }
    return 0;
}
