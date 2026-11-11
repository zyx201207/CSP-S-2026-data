#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
ll CF,n,m,d,q;
ll w[500005],k[505],dis[505][505];
vector<pair<ll,ll> > a[505],sy[500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(dis,0x3f,sizeof(dis));
    cin>>CF>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        dis[i][i]=0;
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            ll x,y;
            cin>>x>>y;
            a[i].push_back({x,y});
            sy[x].push_back({i,y});
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(auto y114514:sy[i])
        {
            for(auto y2:sy[i])
            {
                if(y114514.fi==y2.fi)continue;
                dis[y114514.fi][y2.fi]=min(dis[y114514.fi][y2.fi],y114514.se+y2.se);
            }
        }
    }
    for(int l=1;l<=n;l++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
            }
        }
    }
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        ll ans=0x3f3f3f3f3f3f3f3f;
        for(auto y114514:sy[x])
        {
            for(auto y2:sy[y])
            {
                ans=min(ans,dis[y114514.fi][y2.fi]+y114514.se+y2.se);
            }
        }
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}
