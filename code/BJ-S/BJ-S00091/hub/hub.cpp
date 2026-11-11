#include<bits/stdc++.h>
using namespace std;
const int N=305,inf=1e12;
int c,t,n,k,ans=inf;
int dis[N];
bool a[N],vis[N];
vector<int> g[N];
int find()
{
    int res=0;
    priority_queue<pair<int,int> > q;
    for(int i=1;i<=n;i++) dis[i]=inf,vis[i]=0;
    for(int i=1;i<=n;i++)
        if(a[i])
        {
            q.push({0,i});
            dis[i]=0;
        }
    while(q.size())
    {
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto v:g[u])
        {
            if(dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                q.push({-dis[v],v});
            }
        }
        cout<<u<<" "<<dis[u]<<endl;
    }
    cout<<endl;
    for(int i=1;i<=n;i++) res=max(res,dis[i]);
    return res;
}
void dfs(int step,int pre)
{
    if(step==k)
    {
        ans=min(ans,find());
        return ;
    }
    for(int i=pre+1;i<=n;i++)
    {
        a[i]=1;
        dfs(step+1,i);
        a[i]=0;
    }
    return ;
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        ans=inf;
        cin>>n>>k;
        for(int i=1,u,v;i<n;i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0,0);
        cout<<ans<<endl;
        for(int i=0;i<=n;i++) g[i].clear();
    }
    return 0;
}
