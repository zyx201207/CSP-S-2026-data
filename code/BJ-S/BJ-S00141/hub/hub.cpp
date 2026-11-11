#include <iostream>
#include <vector>
using namespace std;
constexpr int N=1e6+3;
vector<int> son[N];
vector<int> t;
int n,k;
int fa[N],dep[N],sze[N],hson[N];
void dfs1(int u)
{
    sze[u]=1;
    for (auto v:son[u])
    {
        if (v==fa[u]) continue;
        dep[v]=dep[u]+1;
        fa[v]=u;
        dfs1(v);
        if (sze[hson[u]]<sze[v])
        {
            hson[u]=v;
        }
        sze[u]+=sze[v];
    }
}
int top[N];
void dfs2(int u,int t)
{
    top[u]=t;
    if (hson[u]) dfs2(hson[u],t);
    for (auto v:son[u])
    {
        if (v==fa[u]||v==hson[u]) continue;
        dfs2(v,v);
    }
}
int lca(int u,int v)
{
    while (top[u]!=top[v])
    {
        if (dep[top[u]]<dep[top[v]]) swap(u,v);
        u=fa[top[u]];
    }
    return dep[u]<dep[v]?u:v;
}
int dis(int u,int v)
{
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}
int ans=1e9;
void check()
{
    int ed=0;
    for (int i=0;i<t.size();i++)
    {
        for (int j=i+1;j<t.size();j++)
        {
            if (dis(t[i],t[j])==1)
            {
                ed++;
            }
        }
    }
    if (ed<k-2) return;
    int maxmin=0;
    for (int i=1;i<=n;i++)
    {
        int mindis=1e9;
        for (auto x:t)
        {
            mindis=min(mindis,dis(i,x));
            if (mindis==0) break;
        }
        maxmin=max(maxmin,mindis);
    }
    ans=min(ans,maxmin);
}
void dfs(int i)
{
    if (t.size()==k)
    {
        check();
        return;
    }
    for (int j=i+1;j<=n;j++)
    {
        t.push_back(j);
        dfs(j);
        t.pop_back();
    }
}
void solve()
{
    ans=1e9;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        fa[i]=dep[i]=sze[i]=hson[i]=top[i]=0;
        son[i].clear();
    }
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        son[u].push_back(v);
        son[v].push_back(u);
    }
    dfs1(1);
    dfs2(1,1);
    dfs(0);
    // cout<<dis(1,5)<<'\n';
    cout<<ans<<'\n';
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while (t--)
    {
        solve();
    }
}
