#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 12;
int n,k;
vector<int> E[MAXN];
int fa[MAXN];
void dfs1(int u,int f)
{
    fa[u] = f;
    for (int v:E[u])
    {
        if (v==f) continue ;
        dfs1(v,u);
    }
}
int f[MAXN],g[MAXN];
int cur[MAXN];
void dfs2(int u,int fa)
{
    f[u] = 0;
    for (int v:E[u])
    {
        if (v==fa) continue ;
        dfs2(v,u);
        f[u] = max(f[u],f[v]+1);
    }
}
void dfs3(int u,int fa)
{
    // cerr << f[u] << ' ' << g[u] << endl;
    if (g[u]>0)    cur[min(g[u]-1,f[u])] ++;
    for (int v:E[u])
    {
        if (v==fa) continue ;
        g[v] = g[u]+1;
    }
    int mx = -1e9,sub = -1e9;
    for (int v:E[u])
    {
        if (v==fa) continue ;
        if (f[v]>mx) sub = mx,mx = f[v];
        else if (f[v]>sub) sub = f[v];
    }
    for (int v:E[u])
    {
        if (v==fa) continue ;
        if (f[v]==mx) g[v] = max(g[v],sub+2);
        else g[v] = max(g[v],mx+2);
    }
    for (int v:E[u])
    {
        if (v==fa) continue ;
        dfs3(v,u);
    }
}
void work()
{
    cin >> n >> k;
    for (int i=1;i<=n;i++) E[i].clear();
    for (int i=1;i<n;i++)
    {
        int u,v;cin >> u >> v;
        E[u].push_back(v),E[v].push_back(u);
    }
    dfs1(1,0);
    if (n==k) return cout << "0\n",void();
    int res = n;
    for (int u=2;u<=n;u++)
    {
        for (int t=0;t<=n+1;t++) cur[t] = 0;
        int v = fa[u];
        g[u] = g[v] = 0;
        dfs2(v,u),dfs3(v,u);
        dfs2(u,v),dfs3(u,v);
        // cerr << endl;
        for (int i=n;i>=0;i--) cur[i] += cur[i+1];
        // cerr << cur[1] << endl;
        for (int d=1;d<=n;d++)
            if (cur[d]<=k-2) res = min(res,d);
    }
    // cerr << res << endl;
    cout << res << '\n';
}
namespace s1{
int dep[MAXN],dfn[MAXN],st[MAXN][20];
int lg[MAXN];
int fa[MAXN],idx;
void dfs1(int u,int f)
{
    fa[u] = f;
    dep[u] = dep[f] + 1;
    dfn[u] = ++idx;
    st[idx][0] = u;
    for (int v:E[u])
    {
        if (v==f) continue ;
        dfs1(v,u);
    }
}
#define chs(x,y) ((dep[x]<dep[y])?x:y)
inline int lca(int u,int v)
{
    if (u==v) return u;
    if (dfn[u]>dfn[v]) swap(u,v);
    int k = lg[dfn[v]-dfn[u]];
    return fa[chs(st[dfn[u]+1][k],st[dfn[v]-(1<<k)+1][k])];
}
inline int dis(int u,int v)
{
    return dep[u] + dep[v] - 2*dep[lca(u,v)];
}
struct Node{
    int u,v;
};
inline Node merge(const Node&x,const Node&y)
{
    Node z;
    int d = -1;
    vector<int> t;t.push_back(x.u),t.push_back(x.v),t.push_back(y.u),t.push_back(y.v);
    for (int i=0;i<t.size();i++)
        for (int j=i+1;j<t.size();j++)
        {
            int u = t[i],v = t[j];
            int cd = dis(u,v);
            if (cd>d) d = cd,z.u = u,z.v = v;
        }
    return z;
}
Node p[MAXN],q[MAXN];
void dfs2(int u,int f)
{
    p[u] = {u,u};
    for (int v:E[u])
    {
        if (v==f) continue ;
        dfs2(v,u);
        p[u] = merge(p[u],p[v]);
    }
}
int cur[MAXN],m;
Node sl[MAXN],sr[MAXN];
void dfs3(int u,int f)
{
    m = 0;
    for (int v:E[u])
    {
        if (v==f) continue ;
        cur[++m] = v;
    }
    Node o = (f==0)?Node{u,u}:merge(Node{u,u},q[u]);
    sl[0] = o;
    for (int i=1;i<=m;i++) sl[i] = merge(p[cur[i]],sl[i-1]);
    sr[m] = p[cur[m]];
    for (int i=m-1;i>=1;i--) sr[i] = merge(p[cur[i]],sr[i+1]);
    for (int i=1;i<=m;i++)
    {
        Node c = sl[i-1];
        if (i<m) c = merge(c,sr[i+1]);
        q[cur[i]] = c;
    }
    for (int v:E[u])
    {
        if (v==f) continue ;
        dfs3(v,u);
    }
}
void work()
{
    cin >> n >> k;
    for (int i=1;i<=n;i++) E[i].clear();
    for (int i=1;i<n;i++)
    {
        int u,v;cin >> u >> v;
        E[u].push_back(v),E[v].push_back(u);
    }
    idx = 0;
    dfs1(1,0);
    for (int i=2;i<=n;i++) lg[i] = lg[i>>1] + 1;
    for (int k=1;(1<<k)<=n;k++)
        for (int l=1;l+(1<<k)-1<=n;l++)
            st[l][k] = chs(st[l][k-1],st[l+(1<<(k-1))][k-1]);
    dfs2(1,0);
    q[1] = {1,1};
    dfs3(1,0);
    int res = n;
    for (int u=2;u<=n;u++)
    {
        int d = max(dis(p[u].u,p[u].v),dis(q[u].u,q[u].v));
        res = min(res,(d+1)/2);
    }
    cout << res << '\n';
}
}
namespace s2{
bool check(int d)
{
    int m = (n+1)/2;
    for (int i=1;i<=m;i++)
    {
        int d1 = (i==1)?2:i+2;
        int d2 = m-i+1;
        // cerr << d1 << ' ' << d2 << endl;
        if (k>=max(d1-2*d,1)+max(d2-2*d,1)) return 1;
    }
    return 0;
}
void work()
{
    cin >> n >> k;
    for (int i=1;i<=n;i++) E[i].clear();
    for (int i=1;i<n;i++)
    {
        int u,v;cin >> u >> v;
        E[u].push_back(v),E[v].push_back(u);
    }
    if (k>=n) return cout << "0\n",void();
    if (k>=n/2) return cout << "1\n",void();
    int l = 2,r = n,md,res = n;
    while (l<=r)
    {
        md = (l+r)>>1;
        if (check(md)) res = md,r = md-1;
        else l = md+1;
    }
    cout << res << '\n';
}
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int c,t;cin >> c >> t;
    while (t--) 
    {
        if (11<=c&&c<=12) s1::work();
        else if (13<=c&&c<=14) s2::work();
        else work();
    }
    return 0;
}