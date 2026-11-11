#include <bits/stdc++.h>
using namespace std;
long long tim[500005],dis[2005][1505],vis[2005],diss[500005],cwy;
struct edge
{
    int bh,num;
};
bool operator<(const edge &x,const edge &y)
{
    return x.num>y.num;
}
priority_queue<edge> q;
queue<int> q1;
struct node
{
    int v,w;
};
vector<node> vec[500005];
void dij(int x)
{
    dis[x][x]=0;
    q.push({x,0});
    while(!q.empty())
    {
        edge p=q.top();
        q.pop();
        if(vis[p.bh]) continue;
        vis[p.bh]=1;
        for(int i=0;i<vec[p.bh].size();i++)
        {
            node j=vec[p.bh][i];
            if(dis[x][j.v]>dis[x][p.bh]+j.w)
            {
                dis[x][j.v]=dis[x][p.bh]+j.w;
                q.push({j.v,j.w});
            }
        }
    }
    return ;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    int c,n,m,d,q; cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>tim[i];
    for(int i=1;i<=n;i++)
    {
        int tot; cin>>tot;
        for(int j=1;j<=tot;j++)
        {
            int v1,w1; cin>>v1>>w1;
            vec[i+m].push_back({v1,w1});
            vec[v1].push_back({i+m,w1});
            cwy=w1;
            //cout<<i+m<<" "<<v1<<" "<<w1<<" "<<endl;
        }
    }
    if(m>1502)
    {
        while(q--)
        {
            int u,v; cin>>u>>v;
            q1.push(u);
            memset(diss,0x3f,sizeof(diss));
            diss[u]=0;
            while(!q1.empty())
            {
                int p=q1.front();
                q1.pop();
                for(int i=0;i<vec[p].size();i++)
                {
                    int j=vec[p][i].v;
                    if(diss[j]>diss[p]+cwy)
                    {
                        diss[j]=diss[p]+cwy;
                        q1.push(j);
                    }
                }
            }
            cout<<diss[v]+tim[u]+tim[v]<<endl;
        }
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        memset(vis,0,sizeof(vis));
        dij(i);
    }
    /*for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++) cout<<i<<" "<<j<<" "<<dis[i][j]<<endl;
    }*/
    while(q--)
    {
        int u,v; cin>>u>>v;
        cout<<dis[u][v]+tim[u]+tim[v]<<endl;
    }
    return 0;
}
