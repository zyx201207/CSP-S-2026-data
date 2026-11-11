#include<bits/stdc++.h>
#define fir first
#define sec second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read()
{
    ll x=0,t=1;
    char c=getchar();
    while(c<'0' || c>'9')
    {
        if(c=='-')
            t=-1;
        c=getchar();
    }
    while(c>='0' && c<='9')
    {
        x=(x<<1)+(x<<3)+(c^'0');
        c=getchar();
    }
    return x*t;
}
inline void write(ll x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>=10) write(x/10);
    putchar((x%10)^'0');
    return ;
}
inline void write_L(ll x)
{
    write(x);
    putchar('\n');
}
inline void write_(ll x)
{
    write(x);
    putchar(' ');
}
inline void write_P(pll x)
{
    write_(x.fir);
    write_L(x.sec);
}
const ll inf=0x3f3f3f3f3f3f3f3f;
const int M=5e5+10;
const int N=510;
int W[M];
ll edge[N][N];
struct node
{
    ll v,w;
    bool operator <(const node& other) const
    {
        return w<other.w;
    }
};
vector<pii> e[M+10];
vector<node> g[N+10];
ll dist[N][N];
bool vis[N][N],vis1[N][N];
void dij(int s)
{
    priority_queue<node> q;
    q.push({s,0});
    dist[s][s]=0;
    while(!q.empty())
    {
        int u=q.top().v;
        q.pop();
        if(vis[s][u]) continue;
        vis[s][u]=true;
        for(auto i:g[u])
        {
            int v=i.v,w=i.w;
            if(dist[s][u]+w<dist[s][v])
            {
                dist[s][v]=dist[s][u]+w;
                q.push({v,dist[s][v]});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll CASE=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++)
        W[i]=read();
    for(int i=1;i<=n;i++)
    {
        int k=read();
        for(int j=1;j<=k;j++)
        {
            int a=read(),t=read();
            e[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            edge[i][j]=inf;
            dist[i][j]=inf;
        }
    vector<pii> vt;
    for(int i=1;i<=m;i++)
        for(auto j:e[i])
            for(auto k:e[i])
            {
                int u=j.fir,v=k.fir;
                ll now=j.sec+k.sec;
                ll pre=edge[u][v];
                edge[u][v]=edge[v][u]=min(pre,now);
                vt.push_back({u,v});
            }
    for(auto i:vt)
    {
        int u=i.fir,v=i.sec;
        int w=edge[u][v];
        if(vis1[u][v]) continue;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        vis1[u][v]=true;
    }
    for(int i=1;i<=n;i++)
        dij(i);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(!vis[i][j])
                write_P({i,j});
    while(q--)
    {
        int x=read(),y=read();
        ll ans=inf;
        for(auto u:e[x])
            for(auto v:e[y])
                ans=min(ans,dist[u.fir][v.fir]+u.sec+v.sec);
        write_L(ans+W[x]+W[y]);
    }
    return 0;
}

/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

16:31:00
192-200 pts!!
S 1=?
d=2跑了500ms
img d=20 能跑多少
d^2m+n^2logn+q的
hope d=20 AC

*/
