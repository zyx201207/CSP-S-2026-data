#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,d[1000010],f[1000010][20],ans;
vector<int> g[1000010];
bool v[1000010];
void dfs1(int u,int fa)
{
    d[u]=d[fa]+1;
    f[u][0]=fa;
    for(int i=1;i<20;i++) f[u][i]=f[f[u][i-1]][i-1];
    for(int v:g[u])
    {
        if(v==fa) continue;
        dfs1(v,u);
    }
}
int lca(int u,int v)
{
    if(d[u]<d[v]) swap(u,v);
    for(int i=19;i>=0;i--)
    {
        if(d[f[u][i]]>=d[v]) u=f[u][i];
    }
    if(u==v) return v;
    for(int i=19;i>=0;i--)
    {
        if(f[u][i]!=f[v][i])
        {
            u=f[u][i];
            v=f[v][i];
        }
    }
    return f[u][1];
}
void dfs(int p,int num)
{
    if(p==k) 
    {
        ans=min(ans,num);
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(v[i]) continue;
        v[i]=1;
        for(int j=1;j<=n;j++)
        {
            if(v[j]&&i!=j) num=max(num,d[i]+d[j]-2*d[lca(i,j)]);
        }
        dfs(p+1,num);
        v[i]=0;
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        ans=1e9;
        cin>>n>>k;
        for(int i=1;i<=n;i++) g[i].clear(),d[i]=0,v[i]=0;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs1(1,0);
        dfs(0,0);
        cout<<ans<<"\n";
    }
    return 0;
}