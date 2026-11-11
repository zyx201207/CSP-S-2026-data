#include<bits/stdc++.h>
#define maxn 1000006
#define lgn 20
int n,head[maxn],lg[maxn];
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
}
namespace bit
{
    int c[maxn];
    inline void insert(int x,int v){while(x<=n)c[x]+=v,x+=-x&x;}
    inline int query(int x){int ret = 0;while(x)ret+=c[x],x^=-x&x;}
}
namespace lca
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
}
namespace st
{
    int st[maxn][lgn];
    inline void build(int*a)
    {
        for(int i = 1;i<=n;++i)st[i][0] = a[i];
        for(int j = 1;j<=lg[n];++j)
            for(int i = 1;i+(1<<j)-1<=n;++i)
                st[i][j] = std::max(st[i][j-1],st[i+(1<<j-1)][j-1]);
    }
    inline int query(int l,int r)
    {
        int s = lg[r-l+1];
        return std::max(st[l][s],st[r-(1<<s)+1][s]);
    }
}
int main()
{

    return 0;
}
