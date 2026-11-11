#include <bits/stdc++.h>
using namespace std;
#define ll long long
using namespace std;
const int M=500005,N=505;
int c,n,m,d,q,w[M],k[N];
ll f[N][N];
vector<pair<ll,ll>> s[M];
void floyed()
{
    for(int i=1;i<=n;i++)f[i][i]=0;
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                f[j][i]=f[i][j];
            }
        }
    }
}
int main()
{

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        ll x,t;
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>x>>t;
            s[x].push_back({i,t});
        }
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=m;i++)
    {
        for(int p1=0;p1<s[i].size();p1++)
        {
            for(int p2=p1+1;p2<s[i].size();p2++)
            {
                ll w=s[i][p1].second+s[i][p2].second,u=s[i][p1].first,v=s[i][p2].first;
                f[u][v]=min(f[u][v],w);
                f[v][u]=min(f[v][u],w);
            }
        }
    }
    floyed();
    while(q--)
    {
        int xq,yq;
        cin>>xq>>yq;
        ll ans=0x3f3f3f3f3f3f3f3f;
        for(auto [u,t1]:s[xq])
        {
            for(auto [v,t2]:s[yq])
            {
                ans=min(ans,f[u][v]+t1+t2);
            }
        }
        cout<<ans+w[xq]+w[yq]<<'\n';
    }
}
