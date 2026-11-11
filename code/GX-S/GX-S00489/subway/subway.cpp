#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M=5e5;
const int N=500;
const ll inf=1e18;
const int MAXV=M*2+N;
ll c,n,m,d,q,dis[N+5][N+5],cost[M+5];
struct tu
{
    ll v,w;
};
vector <tu> G[M+5];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++) cin>>cost[i];
    for(ll i=1,len;i<=n;i++)
    {
        cin>>len;
        for(ll j=1,v,w;j<=len;j++)
        {
            cin>>v>>w;
            G[v].push_back({i,w});
        }
        for(ll j=1;j<=n;j++)
        {
            if(i!=j) dis[i][j]=inf;
        }
    }
    for(ll i=1;i<=m;i++)
    {
        for(ll j=0;j<G[i].size();j++)
        {
            for(ll e=j+1;e<G[i].size();e++)
            {
                ll x=G[i][j].v,y=G[i][e].v;
                dis[x][y]=min(dis[x][y],G[i][j].w+G[i][e].w);
                dis[y][x]=dis[x][y];
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            for(ll e=1;e<=n;e++) dis[i][j]=min(dis[i][j],dis[i][e]+dis[e][j]);
        }
    }
    for(ll i=1,u,v;i<=q;i++)
    {
        cin>>u>>v;
        ll ans=inf;
        for(ll j=0;j<G[u].size();j++)
        {
            for(ll e=0;e<G[v].size();e++)
            {
                ll x=G[u][j].v,y=G[v][e].v;
                ans=min(ans,dis[x][y]+cost[u]+cost[v]+G[u][j].w+G[v][e].w);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
