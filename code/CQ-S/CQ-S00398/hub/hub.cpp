#include<bits/stdc++.h>
#define ll long long
#define F for
#define W while
using namespace std;
char buf[1<<23],*p1=buf,*p2=buf;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<23,stdin),p1==p2)?EOF:*p1++)
static inline int read()
{
    int x=0,f=1;char ch=gc();
    W(!isdigit(ch)){if(ch=='-')f=-1;ch=gc();}
    W(isdigit(ch)) x=x*10+(ch^48),ch=gc();
    return x*f;
}
const int MAXN=10+5,INF=0x3f3f3f3f;
int n,k,ans;
int col[MAXN];
bool is[MAXN],vis[MAXN];
vector<int> vec,G[MAXN];
void dfs1(int u,int c)
{
    if(!is[u]||vis[u]) return ;
    vis[u]=1;
    col[u]=c;
    F(int v : G[u]) dfs1(v,c);
}
int bfs(int u)
{
    memset(vis,0,sizeof vis);
    queue<pair<int,int>> q;
    q.push({u,0});
    W(!q.empty())
    {
        auto [u,d]=q.front();q.pop();
        if(vis[u]) continue;
        if(is[u]) return d;
        F(int v : G[u]) if(!vis[u]) q.push({v,d+1});
    }
}
void dfs(int i)
{
    if(vec.size()==k)
    {
        memset(vis,0,sizeof vis);
        memset(col,0,sizeof col);
        int cnt=0;
        F(int i : vec)
        {
            if(!vis[i]) dfs1(i,++cnt);
        }
        if(cnt!=2) return ;
        int res=0;
        F(int i=1;i<=n;i++) res=max(res,bfs(i));
        ans=min(ans,res);
        return ;
    }
    if(i==n+1) return ;
    vec.push_back(i);
    is[i]=1;
    dfs(i+1);
    is[i]=0;
    vec.pop_back();
    dfs(i+1);
}
void solve()
{
    // cerr<<111111<<'\n';
    n=read(),k=read();
    F(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ans=INF;
    dfs(1);
    cout<<ans<<'\n';
    F(int i=1;i<=n;i++) G[i].clear();
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c=read(),t=read();
    W(t--) solve();
    return 0;
}