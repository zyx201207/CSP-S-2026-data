#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,p;
ll tim[500010];
struct node
{
    ll to,t;
    bool operator <(const node &x)const
    {
        return x.t<t;
    }
};
vector<node> road[500010];
vector<node> edge[510];
ll dis[510][510];
bool been[510][510];
void sol(int x)
{
    priority_queue<node> q;
    q.push({x,0});
    dis[x][x]=0;
    while(q.empty()==false)
    {
        int t=q.top().to;
        q.pop();
        if(been[x][t]==true)
            continue;
        been[x][t]=true;
        for(int i=0;i<edge[t].size();i++)
        {
            int to=edge[t][i].to,v=edge[t][i].t;
            if(been[x][to]==true||dis[x][to]<dis[x][t]+v)
                continue;
            dis[x][to]=dis[x][t]+v;
            q.push({to,dis[x][to]});
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++)
        cin>>tim[i];
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            ll u,v;
            cin>>u>>v;
            road[u].push_back((node){i,v});
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int t1=0;t1<road[i].size();t1++)
        {
            for(int t2=t1+1;t2<road[i].size();t2++)
            {
                int u=road[i][t1].to;
                int v=road[i][t2].to;
                ll w=road[i][t1].t+road[i][t2].t;
                edge[u].push_back({v,w});
                edge[v].push_back({u,w});
            }
        }
    }
    for(int i=1;i<=n;i++)
        sol(i);
    for(int i=1;i<=p;i++)
    {
        ll x,y,ans=1e18;
        cin>>x>>y;
        for(int t1=0;t1<road[x].size();t1++)
        {
            if(road[x][t1].t>=ans)
                continue;
            for(int t2=0;t2<road[y].size();t2++)
            {
                int u=road[x][t1].to;
                int v=road[y][t2].to;
                ll w=road[x][t1].t+road[y][t2].t;
                ans=min(ans,w+dis[u][v]);
            }
        }
        ans+=tim[x]+tim[y];
        cout<<ans<<'\n';
    }
    return 0;
}
