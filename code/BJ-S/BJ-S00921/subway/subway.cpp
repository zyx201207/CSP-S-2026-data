#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<long long,long long>

const int N=510,M=5e5+10;
int c,n,m,d,q,w[M],ans,sum,dis[M],y;
bool vis[M];
vector<pii> e[M];
vector<int> id[M];

struct node
{
    int a,t,lt;
};

vector<node> g[N];

void dfs(int x,int f)
{
    if(x==y)
    {
        ans=min(ans,sum);
        return ;
    }
    for(int i: id[x])
    {
        for(auto [a,t,lt]: g[i])
        {
            if(a==x||a==f) continue;
            if(vis[a]) continue;
            sum+=t;
            sum+=lt;
            //cout << x << "=>" << a << " " << sum << "\n";
            vis[a]=1;
            dfs(a,x);
            sum-=t;
            sum-=lt;
            vis[a]=0;
        }
    }
}

void dijkstra(int x)
{
    for(int i=1;i<=1000;i++) dis[i]=1e9,vis[i]=0;
    dis[x]=0;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push({0,x});
    while(pq.size())
    {
        int u=pq.top().second; pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto [v,w]: e[u])
        {
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	if(c<=3)
    {
        for(int i=1;i<=n;i++)
        {
            int k; cin >> k;
            int lt=0;
            for(int j=1;j<=k;j++)
            {
                int a,t; cin >> a >> t;
                g[i].push_back({a,t,lt});
                id[a].push_back(i);
                lt=t;
            }
        }
        while(q--)
        {
            int x; cin >> x >> y;
            ans=1e9,sum=0;
            vis[x]=1;
            dfs(x,0);
            cout << ans+w[x]+w[y] << "\n";
        }
    }
	if(7<=c&&c<=11)
    {
        for(int i=1;i<=n;i++)
        {
            int k; cin >> k;
            int u,v,wu,wv; cin >> u >> wu >> v >> wv;
            e[u].push_back({v,wu+wv});
            e[v].push_back({u,wu+wv});
        }
        while(q--)
        {
            int x,y; cin >> x >> y;
            dijkstra(x);
            cout << dis[y]+w[x]+w[y] << "\n";
        }
        return 0;
    }
	return 0;
}
