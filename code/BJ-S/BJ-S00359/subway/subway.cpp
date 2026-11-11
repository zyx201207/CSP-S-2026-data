#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct staion
{
    ll to,v;
};
ll w[500005];
vector<staion> v[500005];
ll f[505][505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(f,0x3f,sizeof(f));
    ll c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;++i)f[i][i]=0;
    for(int i=1;i<=m;++i)cin>>w[i];
    for(int i=1;i<=n;++i)
    {
        int t;
        cin>>t;
        while(t--)
        {
            ll x,y;
            cin>>x>>y;
            v[x].push_back({i,y});
        }
    }
    for(int k=1;k<=m;++k)
    {
        ll l=v[k].size();
        for(int i=0;i<l;++i)
        {
            for(int j=i+1;j<l;++j)
            {
                staion x=v[k][i],y=v[k][j];
                f[x.to][y.to]=min(f[x.to][y.to],x.v+y.v);
                f[y.to][x.to]=f[x.to][y.to];
            }
        }
    }
    for(int k=1;k<=n;++k)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=i+1;j<=n;++j)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                f[j][i]=f[i][j];
            }
        }
    }
    while(q--)
    {
        int s,t;
        cin>>s>>t;
        ll ans=LLONG_MAX;
        for(int i=0;i<v[s].size();++i)
        {
            for(int j=0;j<v[t].size();++j)
            {
                staion x=v[s][i],y=v[t][j];
                ans=min(ans,f[x.to][y.to]+x.v+y.v);
            }
        }
        cout<<ans+w[s]+w[t]<<endl;
    }
    return 0;
}
