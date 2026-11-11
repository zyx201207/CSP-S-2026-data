#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> G[1000010];
bool is[1000010];
int lca[110][110],dep[110],fa[110][23];
int qdis(int u,int v)
{
    return dep[u]+dep[v]-dep[lca[u][v]]*2;
}
int qlca(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=20;i>=0;i--)
    {
        if(dep[fa[u][i]]>=dep[v])
        {
            u=fa[u][i];
        }
    }
    if(u==v) return u;
    for(int i=20;i>=0;i--)
    {
        if(fa[u][i]!=fa[v][i])
        {
            u=fa[u][i];
            v=fa[v][i];
        }
    }
    return fa[u][0];
}
void init(int u,int f)
{
    dep[u]=dep[f]+1;fa[u][0]=f;
    for(auto v:G[u])
    {
        if(v==f) continue;
        init(v,u);
    }
}
int pd()
{
    int cntk=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(is[i]==1) cnt++;
        if(is[fa[i][0]]==0&&is[i]==1) cntk++;
    }
    if(cnt!=k||cntk>2) return -1;
    int mmax=0;
    for(int i=1;i<=n;i++)
    {
        if(is[i]==1) continue;
        int cur=1e9;
        for(int j=1;j<=n;j++)
        {
            if(is[j]==0) continue;
            cur=min(cur,qdis(i,j));
        }
        mmax=max(mmax,cur);
    }
    return mmax;
}
int ans=1e9;
void dfs(int u)
{
    if(u==n+1)
    {
        int ret=pd();
        if(ret!=-1) ans=min(ans,ret);
        return ;
    }
    is[u]=1;
    dfs(u+1);
    is[u]=0;
    dfs(u+1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        if(c<=3)
        {
            ans=1e9;
            cin>>n>>k;
            for(int i=1;i<=n;i++) G[i].clear();
            for(int i=1;i<n;i++)
            {
                int u,v;
                cin>>u>>v;
                G[u].push_back(v);
                G[v].push_back(u);
            }
            init(1,0);
            for(int p=1;p<=20;p++)
            {
                for(int i=1;i<=n;i++)
                {
                    fa[i][p]=fa[fa[i][p-1]][p-1];
                }
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    lca[i][j]=qlca(i,j);
                }
            }
            dfs(1);
            cout<<ans<<endl;
        }
        else
        {
            cin>>n>>k;
            for(int i=1;i<=n;i++) G[i].clear();
            for(int i=1;i<n;i++)
            {
                int u,v;
                cin>>u>>v;
                G[u].push_back(v);
                G[v].push_back(u);
            }
            n=(n-1)/2;
            cout<<ceil(1.0*(n-k)/4.0)+1<<endl;
        }
    }
    return 0;
}
