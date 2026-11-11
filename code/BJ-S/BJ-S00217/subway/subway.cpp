#include <bits/stdc++.h>
#define int long long
using namespace std;

int c,n,m,d,q,k,x,t,l,r,a[500005],dis[505][505];

struct node
{
    int id,t;
};
vector<node>g[500005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>x>>t;
            g[x].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dis[i][j]=9e17;
        }
    }
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        for(auto [id1,t1]:g[i])
        {
            for(auto [id2,t2]:g[i])
            {
                dis[id1][id2]=min(dis[id1][id2],t1+t2);
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--)
    {
        cin>>l>>r;
        int ans=9e18;
        for(auto [id1,t1]:g[l])
        {
            for(auto [id2,t2]:g[r])
            {
                ans=min(ans,dis[id1][id2]+a[l]+t1+a[r]+t2);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}