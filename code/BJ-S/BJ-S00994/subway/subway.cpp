#include<bits/stdc++.h>
#define ll long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
const int N=5e5+505,M=505;

int c,n,m,d,q,k[M];
ll val[N],dis[M][M];
struct E
{
    int v;
    ll w;
};
vector<E> g[N];
inline int read()
{
    int ret=0,fh=1;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar())
        if(ch=='-') fh=-1;
    for(;isdigit(ch);ch=getchar())
        ret=ret*10+ch-'0';
    return ret*fh;
}
inline void write(ll x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
void build_edge(int u)
{
    for(auto i:g[u])
        for(auto j:g[i.v])
            if(u!=j.v)
                dis[u][j.v]=min(dis[u][j.v],i.w+j.w);
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),m=read(),n=read(),d=read(),q=read();
    rep(i,m+1,m+n) val[i]=read();
    rep(i,1,m)
    {
        k[i]=read();
        rep(j,1,k[i])
        {
            int v,w;
            v=read(),w=read();
            v+=m;
            g[i].push_back({v,w});
            g[v].push_back({i,w});
        }
    }
    //地铁站建边
    rep(i,1,m) rep(j,1,m)
        if(i!=j) dis[i][j]=4e18;
    rep(i,1,m) build_edge(i);
    //floyd
    rep(k,1,m) rep(i,1,m) rep(j,1,m)
        if(i!=j&&j!=k)
            dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--)
    {
        int x,y;
        x=read(),y=read();
        x+=m,y+=m;
        ll ans=LLONG_MAX;
        for(auto i:g[x]) for(auto j:g[y])
            ans=min(ans,i.w+dis[i.v][j.v]+j.w);
        ans+=val[x]+val[y];
        write(ans),putchar('\n');
    }
    return 0;
}
//16:44