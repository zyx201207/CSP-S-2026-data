#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PLL pair<ll,ll>
const int N=510;
const int M=5e5+10;
ll c,n,m,d,q;
ll w[M];
ll k[N];
vector<ll> a[N];
vector<ll> t[N];
vector<PLL> g[M+N];
ll dist[M+N],vis[M+N];
ll dij(ll s,ll t)
{
    memset(dist,0X3f,sizeof dist);
    memset(vis,0,sizeof vis);
    priority_queue<PLL,vector<PLL>,greater<PLL>> q;
    dist[s]=0;
    q.push({0,s});
    while(!q.empty())
    {
        auto [x,u]=q.top();
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto [v,w]:g[u])
        {
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                q.push({dist[v],v});
            }
        }
    }
    return dist[t]+w[s]+w[t];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++)
        cin>>w[i];
    for(ll i=1;i<=n;i++)
    {
        cin>>k[i];
        for(ll j=1;j<=k[i];j++)
        {
            ll x,y;
            cin>>x>>y;
            a[i].push_back(x);
            t[i].push_back(y);
            g[m+i].push_back({a[i].back(),t[i].back()});
            g[a[i].back()].push_back({m+i,t[i].back()});
        }
    }
    for(ll i=1;i<=q;i++)
    {
        ll s,t;
        cin>>s>>t;
        cout<<dij(s,t)<<'\n';
    }
    return 0;
}