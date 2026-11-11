#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=1e6+5;
const int inf=1e9;
vector<int> e[N];
int vis[N],fa[N];
int col[N],dep[N];
int ans;
int dis(int x,int y)
{
    int cnt=0;
    if(dep[x]<dep[y]) swap(x,y);
    while(dep[x]>dep[y]) x=fa[x],cnt++;
    while(x!=y) x=fa[x],y=fa[y],cnt+=2;
    return cnt;
}
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    vis[x]=1;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int v:e[u])
        {
            if(vis[v]||col[v]==0) continue;
            q.push(v);
            vis[v]=1;
        }
    }
}
int check(int x)
{
    for(int i=1;i<=n;i++) col[i]=0;
    for(int i=1;i<=n;i++) if((x>>i)&1) col[i]=1;
    int cnt=0;
    for(int i=1;i<=n;i++) vis[i]=0;
    for(int i=1;i<=n;i++) if(!vis[i]&&col[i]) bfs(i),cnt++;
    int num=0;
    if(cnt>2) return inf;
    for(int i=1;i<=n;i++)
    {
        if(col[i]) continue;
        int res=inf;
        for(int j=1;j<=n;j++)
        {
            if(!col[j]) continue;   
            res=min(res,dis(i,j));
        }
        num=max(num,res);
    }
    return num;
}
void dfs1(int x,int num,int cnt)
{
    if(x==n+1)
    {
        if(cnt!=k) return ;
        ans=min(ans,check(num));
        return ;
    }
    dfs1(x+1,num,cnt);
    dfs1(x+1,num|(1<<x),cnt+1);
}
void dfs(int x,int f)
{
    dep[x]=dep[f]+1;
    fa[x]=f;
    for(int v:e[x])
    {
        if(v==f) continue;
        dfs(v,x);
    }
}
void run()
{
    ans=inf;
    cin>>n>>k;
    for(int i=1;i<=n;i++) e[i].clear();
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,1);
    dfs1(1,0,0);
    cout<<ans<<endl;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--) run();
    return 0;
}