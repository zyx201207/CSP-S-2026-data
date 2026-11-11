#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef char ch;
typedef string str;
const ll maxn=510,maxm=5e5+10,inf=1e18;
ll c,n,m,d,q,dis[maxn][maxn],w[maxm];
vector<pair<ll,ll>> sub[maxm];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        ll k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            ll u,t;
            cin>>u>>t,sub[u].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) dis[i][j]=(i==j?0:inf);
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<sub[i].size();j++) 
        {
            ll u=sub[i][j].first,t1=sub[i][j].second;
            for(int k=0;k<sub[i].size();k++)
            {
                ll v=sub[i][k].first,t2=sub[i][k].second;
                dis[v][u]=dis[u][v]=min(dis[u][v],t1+t2);
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
    while(q--)
    {
        ll u,v,ans=inf;
        cin>>u>>v;
        for(int i=0;i<sub[u].size();i++)
        {
            ll x=sub[u][i].first,t1=sub[u][i].second;
            for(int j=0;j<sub[v].size();j++)
            {
                ll y=sub[v][j].first,t2=sub[v][j].second;
                ans=min(ans,dis[x][y]+t1+t2);
            }
        }
        cout<<ans+w[u]+w[v]<<"\n";
    }
}
