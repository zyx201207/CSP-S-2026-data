#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct node{
    int dep,hnode,top,siz,fa,dis;
}tree[N];
vector <int> e[N];
inline void dfs1(int u,int fa,int dis){
    tree[u].dep = tree[fa].dep + 1,tree[u].siz = 1,tree[u].fa = fa,tree[u].dis = dis,tree[u].hnode = 0;
    for (int i:e[u]){
        if (i == fa) continue;
        dfs1(i,u,dis + 1),tree[u].siz += tree[i].siz;
        if (tree[i].siz > tree[tree[u].hnode].siz) tree[u].hnode = i;
    }
}
inline void dfs2(int u,int top){
    if (tree[u].hnode) dfs2(tree[u].hnode,top);
    tree[u].top = top;
    for (int i:e[u]) if (i != tree[u].hnode && i != tree[u].fa) dfs2(i,i);
}
inline int query(int u,int v){
    while (tree[u].top != tree[v].top){
        if (tree[tree[u].top].dep > tree[tree[v].top].dep) swap(u,v);
        v = tree[tree[v].top].fa;
    }
    return (tree[u].dep > tree[v].dep?v:u);
}
#define dist(u,v) (tree[u].dis + tree[v].dis - (tree[query(u,v)].dis << 1))
const int inf = 0x3f3f3f3f;
int c,t,n,u,v,ans,S,k;
bool vis[N];
inline void dfs(int u){
    if (!(S & (1 << (u - 1)))) return;
    if (vis[u]) return;
    vis[u] = true;
    for (int i:e[u]) dfs(i);
}
inline int check(){
    if (__builtin_popcount(S) != k) return inf;
    int cnt = 0;
    memset(vis,0,sizeof(vis));
    for (int i = 1;i <= n;++i){
        if (!vis[i] && (S & (1 << (i - 1)))) dfs(i),++cnt;
        if (cnt > 2) return inf;
    }
    int res = 0;
    for (int i = 1;i <= n;++i){
        if (S & (1 << (i - 1))) continue;
        int p = inf;
        for (int j = 1;j <= n;++j) if (S & (1 << (j - 1))) p = min(p,dist(i,j));
        res = max(res,p);
    }
    return res;
}
inline void solve(){
    ans = inf;
    cin >> n >> k;
    for (int i = 1;i <= n;++i) e[i].clear();
    for (int i = 1;i < n;++i){
        cin >> u >> v;
        e[u].push_back(v),e[v].push_back(u);
    }
    dfs1(1,0,0),dfs2(1,1);
    for (S = 1;S < (1 << n);++S) ans = min(ans,check());
    cout << ans << "\n";
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    while (t--) solve();
    return 0;
}