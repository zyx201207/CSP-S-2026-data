#include<bits/stdc++.h>
using namespace std;
const int N=500+10,M=5e5+10;
int c,n,m,d,q;
int w[M];
int head[M],nxt[M*2],edge[M*2],ver[M*2],idx;
int idxx=500000;
void add(int x,int y,int z)
{
    ver[++idx]=y,edge[idx]=z,nxt[idx]=head[x],head[x]=idx;
}
bool vis[M];
int dis[M];
int maxx;
int diss[1400][1400];
void dij(int x)
{
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    priority_queue<pair<int,int>> q;
    q.push(make_pair(0,x));
    dis[x]=0;
    while(!q.empty())
    {
        int u=q.top().second;q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int idx=head[u];idx;idx=nxt[idx])
        {
            int v=ver[idx],w=edge[idx];
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                q.push(make_pair(-dis[v],v));
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    //cout<<"hello";
    cin>>c>>n>>m>>d>>q;
    //cout<<"hello";
    for(int i=1;i<=m;++i)
    {
        scanf("%d",&w[i]);
    }
    //cout<<"hello";
    for(int i=1;i<=n;++i)
    {
        int x;
        scanf("%d",&x);
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        add(a,idxx,b);
        add(idxx,a,b);
        add(c,idxx,d);
        add(idxx,c,d);
        idxx--;
        maxx=max({a,b,maxx});
    }
    for(int i=1;i<=maxx;++i)
    {
        dij(i);
        for(int j=1;j<=maxx;++j)diss[i][j]=dis[j];
    }
    for(int i=1;i<=q;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        //dij(a);
        printf("%d\n",diss[a][b]+w[a]+w[b]);
    }
    return 0;
}
