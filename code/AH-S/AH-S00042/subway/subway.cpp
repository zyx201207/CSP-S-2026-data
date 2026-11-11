#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500005,mod=998244353;
ll c,n,m,d,q,w[N],f[505][505],a,b;
vector<pair<ll,ll> > g[N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1,k;i<=n;i++)
    {
        f[i][i]=0;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a>>b;
            for(auto e:g[a])
            {
                ll v=e.first,w=e.second;
                if(f[i][v]>b+w)f[i][v]=f[v][i]=b+w;
            }
            g[a].push_back(make_pair(i,b));
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(f[i][j]>f[i][k]+f[k][j])
                {
                    f[i][j]=f[j][i]=f[i][k]+f[k][j];
                }
            }
        }
    }
    while(q--)
    {
        ll x,y,ans=1e18;
        cin>>x>>y;
        for(auto v:g[x])
        {
            for(auto w:g[y])
            {
                ans=min(ans,f[v.first][w.first]+v.second+w.second);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
