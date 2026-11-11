//floyd求出两两地铁路线之间的最短步行时间，询问枚举两端的站点从哪个地铁路线进/出
//pts in optimistic:100
#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rof(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define sc second
#define pb push_back
#define pii pair<int,int>
#define vec vector
using namespace std;
const int N=5e2+5,M=5e5+5,D=25;
int c,n,m,d,q;
int dis[N][N],w[M],k[N];
vec<pii>ed[N];
vec<pii>Ed[M];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>c>>n>>m>>d>>q;
    For(i,1,m)
        cin>>w[i];
    For(i,1,n)
    {
        cin>>k[i];
        For(j,1,k[i])
        {
            int a,b;cin>>a>>b;
            ed[i].pb({a,b});
            Ed[a].pb({i,b});
        }
    }
    memset(dis,0x3f,sizeof dis);
    For(i,1,n)
        dis[i][i]=0;
    For(i,1,m)
    {
        for(pii x:Ed[i])
        {
            for(pii y:Ed[i])
            {
                if(x.fi==y.fi)
                    continue;
                dis[x.fi][y.fi]=min(dis[x.fi][y.fi],x.sc+y.sc);
            }
        }
    }
    For(k,1,n)
        For(i,1,n)
            For(j,1,n)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--)
    {
        int u,v;cin>>u>>v;
        int ans=2e18;
        for(pii x:Ed[u])
        {
            for(pii y:Ed[v])
            {
                ans=min(ans,w[u]+w[v]+dis[x.fi][y.fi]+x.sc+y.sc);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}