#include<bits/stdc++.h>
using namespace std;
int n,m,d,q,tot;
vector<long long> dis[510];
vector<int> nG[510];
long long w[500010];
int vis[510];
long long e[510][510];
priority_queue<pair<long long,int>> que;
inline void dijk(int id)
{
    dis[id].resize(n+5);
    for(int i=1;i<=n;i++) dis[id][i]=1e18;
    dis[id][id]=0;
    que.push({-dis[id][id],id});
    while(!que.empty())
    {
        int u=que.top().second;
        que.pop();
        if(vis[u]==id) continue;
        vis[u]=id;
        for(auto v:nG[u])
        {
            if(dis[id][v]>dis[id][u]+e[v][u])
            {
                dis[id][v]=dis[id][u]+e[v][u];
                que.push({-dis[id][v],v});
            }
        }
    }
    return ;
}
vector<pair<int,long long>> G[500510];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>n>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    tot=m;
    for(int i=1;i<=n;i++)
    {
        int k,u,t;
        cin>>k;
        tot++;
        for(int j=1;j<=k;j++)
        {
            cin>>u>>t;
            G[tot].push_back({u,t});
            G[u].push_back({tot,t});
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            e[i][j]=1e18;
        }
    }
    int u,v;
    long long dist;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<G[i].size();j++)
        {
            for(int k=j+1;k<G[i].size();k++)
            {
                u=G[i][j].first-m,v=G[i][k].first-m;dist=G[i][k].second+G[i][j].second;
                if(e[u][v]==1e18)
                {
                    nG[u].push_back(v);
                    nG[v].push_back(u);
                }
                if(e[u][v]>dist)
                {
                    e[u][v]=dist;
                    e[v][u]=dist;
                }
            }
        }
    }
    for(int i=1;i<=n;i++) dijk(i);
    long long ans;
    while(q--)
    {
        cin>>u>>v;
        ans=1e18;
        for(auto x:G[u])
        {
            for(auto y:G[v])
            {
                ans=min(ans,dis[x.first-m][y.first-m]+x.second+y.second);
            }
        }
        cout<<ans+w[u]+w[v]<<'\n';
    }
    return 0;
}
