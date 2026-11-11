#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,T;
int w[500005];
int st,ed;
struct node
{
    int v,w;
};
vector<node>G[500005];
int ans;
bool vis[500005];
void dfs(int u,int dis)
{
    if(dis>ans)return;
    if(u==ed)
    {
        ans=min(ans,dis);
        return;
    }
    vis[u]=1;
    for(int i=0;i<G[u].size();i++)
    {
        if(!vis[G[u][i].v])
        {
            dfs(G[u][i].v,dis+G[u][i].w);
        }
    }
    vis[u]=0;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>T;
    for(int i=1;i<=m;i++)cin>>w[i];
    m++;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        int bfr=0;
        for(int i=1;i<=k;i++)
        {
            int a,t;
            cin>>a>>t;
            G[m].push_back({a,t});
            G[a].push_back({m,t});
            if(bfr!=0)
            {
                G[bfr].push_back({m,0});
                G[m].push_back({bfr,0});
            }
            bfr=m++;
        }
    }
    while(T--)
    {
        cin>>st>>ed;
        ans=1e15;
        dfs(st,0);
        cout<<w[st]+ans+w[ed]<<'\n';
    }
    return 0;
}
