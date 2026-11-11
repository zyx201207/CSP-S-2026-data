#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=2e6+10;
int c,n,k,ans;
vector<int>edge[N];
int col[N],tot,mx;
int vis[N];
void dfs1(int u)
{
    if(!col[u] || vis[u]) return; 
    vis[u]=1; tot++;
    for(int v:edge[u]) dfs1(v);
}
void dfs2(int u,int dep)
{
    if(vis[u]) return ;
    vis[u]=1;
    if(col[u]) 
    {
        mx=min(mx,dep);
        return ;
    }
    for(int v:edge[u]) dfs2(v,dep+1);
}
void dfs(int p)
{
    if(p==n)
    {
        int cnt=0,now=0; tot=0;
        for(int i=1;i<=n;i++) vis[i]=0;
        for(int i=1;i<=n;i++) if(col[i] && !vis[i]) cnt++,dfs1(i);
        if(cnt>2 || !cnt || tot>k) return ;
        for(int i=1;i<=n;i++) if(!col[i])
        {
            for(int j=1;j<=n;j++) vis[j]=0;
            mx=1e9;
            dfs2(i,0);
            now=max(now,mx);
        }
        ans=min(ans,now);
        return ;
    }
    col[p+1]=0;
    dfs(p+1);
    col[p+1]=1;
    dfs(p+1);
}
void run()
{
    cin>>n>>k; ans=1e9;
    for(int i=1;i<=n;i++) edge[i].clear();
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        edge[u].pb(v);
        edge[v].pb(u);
    }
    dfs(0);
    cout<<ans<<endl;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int t;
    cin>>c>>t;
    while(t--) run();
    return 0;
}