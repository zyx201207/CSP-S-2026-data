#include<bits/stdc++.h>
#define endl '\n'
#define pii pair<int,int> 
#define fi first
#define se second
#define ll long long 
using namespace std;
int c,n,m,d,q;
const int N=5e5+5;
const int M=505;
const long long  inf=1e18;
int w[N];
vector<pii> g[N];
ll dis[M][M];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    memset(dis,0x3f,sizeof(dis));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++) cin>>w[i];
    int tot=0;
    for(int i=1;i<=n;i++)
    {
        int k;cin>>k;
        tot++;
        for(int j=1;j<=k;j++) 
        {
            int x,y;cin>>x>>y;
            g[x].push_back({tot,y});
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<g[i].size();j++)
        {
            for(int k=j+1;k<g[i].size();k++)
            {
                int p1=g[i][j].fi,p2=g[i][k].fi;
                dis[p1][p2]=min(dis[p1][p2],(ll)g[i][j].se+g[i][k].se);
                dis[p2][p1]=min(dis[p2][p1],(ll)g[i][j].se+g[i][k].se);
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        ll ans=inf;
        for(int i=0;i<g[x].size();i++)
        {
            for(int j=0;j<g[y].size();j++)
            {
                int p1=g[x][i].fi,p2=g[y][j].fi;
                ans=min(ans,dis[p1][p2]+g[x][i].se+g[y][j].se);
            }   
        }
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}