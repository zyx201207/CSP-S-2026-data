#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,Q,cnt;
int w[500010],dis[1000010],vis[1000010],head[1000010],l[7010][7010];
struct node
{
    int pos,dis;
    bool operator <(const node&x) const
    {
        return x.dis<dis;
    }
};
priority_queue<node> q;
struct edge
{
    int to,dis;
};
vector<edge> e[20000010];
void add(int u,int v,int w)
{
    e[u].push_back((edge){v,w});
    e[v].push_back((edge){u,w});
}
void dij(int x,int y)
{
    for(int i=1;i<=m+n;i++)
    {
        dis[i]=999999999;
        vis[i]=0;
    }
    dis[x]=0;
    q.push((node{x,0}));
    while(!q.empty())
    {
        int p=q.top().pos;
        q.pop();
        vis[p]=1;
        for(int i=0;i<e[p].size();i++)
        {
            if(e[p][i].dis+dis[p]<dis[e[p][i].to]) dis[e[p][i].to]=e[p][i].dis+dis[p];
            if(!vis[e[p][i].to]) q.push((node{e[p][i].to,dis[e[p][i].to]}));
        }
    }
    if(m<7009) for(int i=1;i<=m;i++) l[x][i]=dis[i];
    cout<<dis[y]+w[x]+w[y]<<endl;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int x,t;
            cin>>x>>t;
            add(x,m+i,t);
        }
    }
    while(Q--)
    {
        int x,y;
        cin>>x>>y;
        if(l[x][y]) cout<<l[x][y]<<endl;
        dij(x,y);
    }
    return 0;
}
