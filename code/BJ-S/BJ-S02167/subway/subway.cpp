#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500010
#define M 510
#define pii pair<ll,ll>
#define fs first
#define sc second
int _,n,m,d,q;
int w[N];
vector<pii> g[N+M];
ll dis[N+M];
bool vis[N+M];
ll dijkstra(int s,int t)
{
    for(int i=1;i<=n+m;i++) dis[i]=1e18,vis[i]=false;
    dis[s]=0;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,s});
    while(!q.empty())
    {
        int u=q.top().sc;
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(auto ed:g[u])
        {
            ll v=ed.fs,W=ed.sc;
            if(dis[v]>dis[u]+W)
            {
                dis[v]=dis[u]+W;
                q.push({dis[v],v});
            }
            if(v==t) return dis[t];
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>_>>m>>n>>d>>q;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1,k,a,t;i<=m;i++)
    {
        cin>>k;
        while(k--)
        {
            cin>>a>>t;
            g[a].push_back({n+i,t});
            g[n+i].push_back({a,t});
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<dijkstra(x,y)+w[x]+w[y]<<"\n";
    }
    return 0;
}