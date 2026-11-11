#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int,int>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
using namespace std;
constexpr int N=1e6+5,inf=1e9;
int cid,T;
int n,k;
pii ed[N];
vi e[N],lf;
namespace sub1
{
    int fa[N],ans;
    bool vis[N];
    int find(int x)
    {
        return fa[x]==x?x:fa[x]=find(fa[x]);
    }
    void merge(int x,int y)
    {
        x=find(x),y=find(y);
        if(x==y)return;
        fa[x]=y;
    }
    int ff[N],top[N],dep[N],son[N],siz[N];
    void dfs1(int u,int faa)
    {
        ff[u]=faa;
        dep[u]=dep[faa]+1;
        siz[u]=1;
        for(auto v:e[u])
        {
            if(v==faa)continue;
            dfs1(v,u);
            if(siz[son[u]]<siz[v])son[u]=v;
        }
    }
    void dfs2(int u,int tp)
    {
        if(son[u])dfs2(son[u],tp);
        for(auto v:e[u])
        {
            if(v==son[u] || v==ff[u])continue;
            dfs2(v,v);
        }
    }
    int lca(int x,int y)
    {
        while(top[x]!=top[y])
        {
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            x=ff[top[x]];
        }
        return dep[x]<dep[y]?x:y;
    }
    int dis(int x,int y)
    {
        return -2*dep[lca(x,y)]+dep[x]+dep[y];
    }
    bool chk(int S)
    {
        if(__builtin_popcount(S)!=k)return false;
        for(int i=1;i<=n;i++)fa[i]=i,vis[i]=0;
        for(int i=1;i<=n;i++)
            if(S&(1<<(i-1)))
                for(auto v:e[i])
                    if(S&(1<<(v-1)))
                        merge(i,v);
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(S&(1<<(i-1)))
                if(!vis[find(i)])
                    vis[find(i)]=1,cnt++;
        if(cnt>2)return false;
        int ret=0;
        for(int i=1;i<=n;i++)
        {
            if(S&(1<<(i-1)))continue;
            int len=inf;
            for(int j=1;j<=n;j++)
                if(S&(1<<(j-1)))
                    len=min(len,dis(i,j));
            ret=max(ret,len);
        }
        ans=min(ans,ret);
        return true;
    }
    void solve()
    {
        while(T--)
        {
            scanf("%d%d",&n,&k);
            for(int i=1,u,v;i<n;i++)
            {
                scanf("%d%d",&u,&v);
                e[u].pb(v),e[v].pb(u);
                ed[i]=mp(u,v);
            }
            dfs1(1,0);
            dfs2(1,1);
            ans=inf;
            for(int S=0;S<(1<<n);S++)
                chk(S);
            printf("%d\n",ans);
            for(int i=1;i<=n;i++)e[i].clear(),siz[i]=0,son[i]=0,ff[i]=0,top[i]=0,dep[i]=0;
        }
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&cid,&T);
    if(cid<=6)
        sub1::solve();
    else if(cid>=13 && cid<=14)
    {
        while(T--)
        {
            scanf("%d%d",&n,&k);
            for(int i=1,u,v;i<n;i++)
                scanf("%d%d",&u,&v);
            printf("%d\n",(int)ceil(1.0*(n/2+4-k)/4.0));
        }
    }
    return 0;
}