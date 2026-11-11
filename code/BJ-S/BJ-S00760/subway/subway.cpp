#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct sub
{
    int a,b,id;
}a[N];
int u[N];
struct road
{
    int x1,x2;
}k[N];
struct edge
{
    int v,w;
};
vector<edge>G[N];
struct node
{

    int dis,now;
    friend bool operator<(const node &x,const node &y)
    {

        return x.dis>y.dis;
    }
};
bool vis[N];
int dij(int s,int ed)
{
    int d[N];
    priority_queue<node>q;
    memset(d,0x3f3f3f3f,sizeof d);
    memset(vis,true,sizeof vis);
    d[s]=0;
    q.push({0,s});
    while(!q.empty())
    {
        int u=q.top().now;
        q.pop();
        if(vis[u]==false)
        {
            continue;
        }
        vis[u]=false;
        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i].v,w=G[u][i].w;
            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                q.push({d[v],v});
            }
        }
    }
    return d[ed];
}

int main()
{
   freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
    int c,n,m,d,p;
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i];
    }
    for(int q=1;q<=n;q++)
    {
        int x;
        cin>>x;
        for(int i=1;i<=x;i++)
        {
            cin>>a[i].a>>a[i].b;
        }
        for(int i=1;i<=x;i++)
        {
            G[a[i].a].push_back({a[i+1].a,a[i].b});
            G[a[i+1].a].push_back({a[i].a,a[i].b});
        }
    }
    for(int i=1;i<=p;i++)
    {
        cin>>k[i].x1>>k[i].x2;
        cout<<dij(k[i].x1,k[i].x2)+u[k[i].x1]+u[k[i].x2]+a[k[i].x1].b+a[k[i].x2].b;
    }
}
