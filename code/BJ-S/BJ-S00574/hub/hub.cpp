#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6+10, L = 21, inf = 1e8;
int c,T,fa[N][L+1],d[N],n,k,chs[N],ufa[N],inchs[N],ans=inf;
vector<int> g[N];
inline void add(int u,int v) { g[u].push_back(v); }
void dfs1(int u,int f) {
    fa[u][0]=f,d[u]=d[f]+1;
    for(int j=1;j<=L;j++)
        fa[u][j]=fa[fa[u][j-1]][j-1];
    for(int v : g[u]) {
        if(v==f) continue;
        dfs1(v,u);
    }
}
int lca(int u,int v) {
    if(d[u]<d[v]) swap(u,v);
    for(int i=L;i>=0;i--)
        if(d[fa[u][i]]>=d[v])
            u=fa[u][i];
    if(u==v) return u;
    for(int i=L;i>=0;i--)
        if(fa[u][i]!=fa[v][i])
            u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
inline void init() { for(int i=1;i<=n;i++) ufa[i]=i; }
int find(int x) { return ufa[x]==x ? x : (ufa[x]=find(ufa[x])); }
inline void merge(int x,int y) {
    x=find(x),y=find(y);
    if(x==y) return;
    ufa[x]=y;
}
void dfs3(int u,int f) {
    for(int v : g[u]) {
        if(v==f) continue;
        if(inchs[u] && inchs[v]) merge(u,v);
        dfs3(v,u);
    }
}
inline int gets(int u,int v) { return d[u]+d[v]-2*d[lca(u,v)]; }
set<int> st;
void dfs2(int d,int s) {
    if(s+n-d+1<k) return ;
    if(s>=k) {
        init();
        dfs3(1,0);
        st.clear();
        for(int i=1;i<=k;i++) {
            int u=chs[i];
            ufa[u]=find(u);
            st.insert(find(u));
        }
        if(st.size()>2) return ;
        else {
            int mx=0;
            for(int i=1;i<=n;i++) {
                if(inchs[i]) continue;
                int mi=inf;
                for(int j=1;j<=k;j++)
                    mi=min(mi,gets(i,chs[j]));
                mx=max(mx,mi);
            }
            ans=min(ans,mx);
        }
        return ;
    }
    chs[s+1]=d;
    inchs[d]=1;
    dfs2(d+1,s+1);
    chs[s+1]=0;
    inchs[d]=0;
    dfs2(d+1,s);
}
signed main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>c>>T;
    while(T--) {
        cin>>n>>k;
        ans=inf;
        memset(fa,0,sizeof(fa));
        memset(d,0,sizeof(d));
        memset(chs,0,sizeof(chs));
        memset(ufa,0,sizeof(ufa));
        memset(inchs,0,sizeof(inchs));
        st.clear();
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=1;i<n;i++) {
            int u,v;
            cin>>u>>v;
            add(u,v); add(v,u);
        }
        dfs1(1,0);
        dfs2(1,0);
        cout<<ans<<'\n';
    }
    return 0;
}