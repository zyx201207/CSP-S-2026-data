#include<bits/stdc++.h>
#define int long long
#define lgn 21
#define maxn 2000006
int T,n,k,head[maxn],lg[maxn],ans,cnt = 0;
struct edge{int nxt,v;}e[maxn<<1];
inline int read()
{
    int x = 0,f = 1;char ch = getchar();
    while(ch<'0'||ch>'9')f = ch == '-'?-f:f,ch = getchar();
    while(ch>='0'&&ch<='9')x = (x<<3)+(x<<1)+(ch^'0'),ch = getchar();
    return x*f;
}
inline void write(int x)
{
    if(x<0)putchar('-'),x = -x;
    static char sta[35];int top = 0;
    do sta[top++] = x%10,x/=10;while(x);
    while(top)putchar(sta[--top]^'0');
    putchar('\n');
}
namespace dis
{
    int fa[maxn][lgn],dep[maxn];
    inline void dfs(int u)
    {
        for(int i = 1;dep[u]>>i;++i)
            fa[u][i] = fa[fa[u][i-1]][i-1];
        for(int i = head[u],v;v = e[i].v,i;i = e[i].nxt)
            if(v!=fa[u][0])fa[v][0] = u,dep[v] = dep[u]+1,dfs(v);
    }
    inline int lca(int u,int v)
    {
        if(dep[u]<dep[v])std::swap(u,v);
        int d = dep[u]-dep[v];
        for(int i = 0;d>>i;++i)
            if(d>>i&1)u = fa[u][i];
        if(u == v)return u;
        for(int i = lg[dep[u]];~i;--i)
            if(fa[u][i]!=fa[v][i])
                u = fa[u][i],v = fa[v][i];
        return fa[u][0];
    }
    inline int dis(int u,int v){return dep[u]+dep[v]-(dep[lca(u,v)]<<1);}
    inline void clear(){memset(fa+1,0,sizeof(fa[0])*n);}
}
inline int popcount(int x){return x?popcount(x^(-x&x))+1:0;}
namespace dsu
{
    int fa[maxn];
    inline int find(int u){return fa[u] == u?u:fa[u] = find(fa[u]);}
    inline void build(){for(int i = 1;i<=n;++i)fa[i] = i;}
    inline bool merge(int u,int v)
    {
        u = find(u),v = find(v);
        if(u == v)return false;
        return fa[u] = v,true;
    }
}
inline bool check(int s)
{
    int cnt = k;dsu::build();
    for(int u = 1;u<=n;++u)if(s>>(u-1)&1)
        for(int i = head[u],v;v = e[i].v,i;i = e[i].nxt)if(s>>(v-1)&1)
            cnt-=dsu::merge(u,v);
    return cnt<=2;
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    read(),T = read();
    while(T--)
    {
        n = read(),k = read(),ans = n*n;
        for(int i = 2;i<=n;++i)lg[i] = lg[i>>1]=1;
        for(int i = 1,u,v;i<n;++i)
        {
            u = read(),v = read();
            e[++cnt] = {head[u],v},head[u] = cnt;
            e[++cnt] = {head[v],u},head[v] = cnt;
        }
        dis::dfs(1);
        for(int s = 0,sum;s<(1<<n);++s)if(popcount(s) == k&&check(s))
        {
            sum = 0;
            for(int i = 0,now;i<n;++i)
            {
                now = n;
                for(int j = 0;j<n;++j)if(s>>j&1)
                    now = std::min(now,dis::dis(i+1,j+1));
                sum = std::max(sum,now);
            }
            ans = std::min(ans,sum);
        }
        write(ans);
        memset(head+1,0,sizeof(int)*n),dis::clear();;

    }
    return 0;
}
