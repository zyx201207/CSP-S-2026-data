#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls x<<1
#define rs x<<1|1
using namespace std;
const int M=5e5+5,N=501,D=21;
int c,n,m,q,w[M];
bool b[M];
struct node
{
    int x,v;
    bool operator<(const node &other)const {return v>other.v;}
}d[M][D];
ll cnt[M],p[N][N],dis[N][N],l[M][N];
priority_queue<node>qu;
ll mn(ll x,ll y)
{
    if(x<y)return x;
    return y;
}
void bfs(int x)
{
    qu.push({x,0});
    dis[x][x]=0;
    while(!qu.empty())
    {
        int g=qu.top().x,val=qu.top().v;
        qu.pop();
        if(val>dis[x][g])continue;
        for(int i=1;i<=n;i++)
        {
            if(dis[x][i]>dis[x][g]+p[g][i])
            {
                dis[x][i]=dis[x][g]+p[g][i];
                qu.push({i,dis[x][i]});
            }
        }
    }
    return;
}
void check(int x)
{
    if(b[x])return;
    b[x]=1;
    for(int j=1;j<=cnt[x];j++)
    {
        int g=d[x][j].x,val=d[x][j].v;
        for(int k=1;k<=n;k++)l[x][k]=min(l[x][k],val+dis[g][k]);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>c>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        cin>>x;
        for(int j=1;j<=x;j++)
        {
            cin>>y>>z;
            d[y][++cnt[y]]={i,z};
        }
    }
    for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)l[i][j]=1e18;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)p[i][j]=dis[i][j]=1e18;
    for(int i=1;i<=m;i++)for(int j=1;j<cnt[i];j++)for(int k=j+1;k<=cnt[i];k++)
    {
        int x=d[i][j].x,y=d[i][k].x,val=d[i][j].v+d[i][k].v;
        p[y][x]=p[x][y]=mn(p[x][y],val);
    }
    for(int i=1;i<=n;i++)bfs(i);
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        check(x);
        check(y);
        ll ans=1e18;
        for(int i=1;i<=n;i++)ans=min(ans,l[x][i]+l[y][i]);
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
