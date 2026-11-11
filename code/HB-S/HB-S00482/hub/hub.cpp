#include <bits/stdc++.h>
using namespace std;
vector<int> g[1000005];
int f[1000005];
int mx[1000005];
int dep[1000005];
int ufa[1000005];
int siz[1000005];
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    mx[u]=1;
    for(int v:g[u])
    {
        if(v^fa)
        {
            dfs(v,u);
            mx[u]=max(mx[u],mx[v]+1);
        }
    }
}
int x=0;
void dfs2(int u,int fa)
{
    f[u]=1;
    for(int v:g[u])
    {
        if(v^fa)
        {
            dfs2(v,u);
            if(mx[v]>x) f[u]+=f[v];
        }
    }
}
int in[1000005];
int rt=0;
int n,k;
void dfs4(int u,int fa)
{
    siz[u]=1;
    ufa[u]=fa;
    int mx=0;
    for(int v:g[u])
    {
        if(v^fa)
        {
            dfs4(v,u);
            siz[u]+=siz[v];
            mx=max(mx,siz[v]);
        }
    }
    if(max(mx,n-siz[u])<=n/2)
    {
        rt=u;
    }
}
int m;
bool flag=false;
void p(int u,int fa,int ur)
{
    if(max(dep[u]-1,dep[ur]-1)+m<=x&&f[u]+f[ur]<=k)
    {
        flag=true;
        return;
    }
    for(int v:g[u])
    {
        if(v==fa) continue;
        p(v,u,ur);
    }
}
void d(int u,int fa,int vrt)
{
    p(vrt,rt,u);
    for(int v:g[u])
    {
        if(v==fa) continue;
        d(v,u,vrt);
    }
}
int mxx[5005][5005];
bool check()
{
    if(f[rt]<=k) return 1;
    flag=false;
    for(int i=1;i<=g[rt].size();i++)
    {
        for(int j=i+1;j<=g[rt].size();j++)
        {
            int u=g[rt][i-1],v=g[rt][j-1];
            m=max({mxx[1][i-1],mxx[i+1][j-1],mxx[j+1][g[rt].size()]});
            d(u,rt,v);
            if(flag) return 1;
        }
    }
    return 0;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
        }
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(n>4000)
        {
            int m=n/2+1;
            cout<<(m+1-k)/4+1<<'\n';
            continue;
        }
        dfs4(1,0);
        dfs(rt,0);
        for(int i=1;i<=g[rt].size();i++)
        {
            for(int j=1;j<=g[rt].size();j++)
            {
                mxx[i][j]=0;
            }
        }
        for(int i=1;i<=g[rt].size();i++)
        {
            for(int j=i;j<=g[rt].size();j++)
            {
                mxx[i][j]=max(mxx[i][j-1],mx[g[rt][j-1]]);
            }
        }
        if(n==k)
        {
            cout<<0<<'\n';
            continue;
        }
        int l=1,r=n,ans=0;
        while(l<=r)
        {
            x=(l+r)/2;
            dfs2(rt,0);
            if(check())
            {
                r=x-1;
                ans=x;
            }
            else
            {
                l=x+1;
            }
        }
        cout<<ans<<'\n';
    }
}