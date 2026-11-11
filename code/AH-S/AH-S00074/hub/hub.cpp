#include <bits/stdc++.h>
using namespace std;

const int N=1e6+6;
int c,T,n,k,ans,fa[N],dep[N],siz[N],hson[N],top[N];
vector<int> e[N];
bitset<N> vis,vis1;

void dfs1(int u,int f) {
    fa[u]=f;
    dep[u]=dep[f]+1;
    siz[u]=1;
    for (int v:e[u]) {
        if (v==f) continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        if (siz[v]>siz[hson[u]]) hson[u]=v;
    }
}

void dfs2(int u,int Top) {
    top[u]=Top;
    if (hson[u]) dfs2(hson[u],Top);
    for (int v:e[u]) {
        if (v==fa[u]||v==hson[u]) continue;
        dfs2(v,v);
    }
}

int dis(int u,int v) {
    int res=dep[u]+dep[v];
    while (top[u]!=top[v]) {
        if (dep[top[u]]<dep[top[v]]) swap(u,v);
        u=fa[top[u]];
    }
    if (dep[u]>dep[v]) swap(u,v);
    res-=2*dep[u];
    return res;
}

void dfs0(int u,int f) {
    vis1[u]=1;
    for (int v:e[u]) {
        if (v==f||!vis[v]) continue;
        dfs0(v,u);
    }
}

bool check() {
    int cnt=0;
    vis1.reset();
    for (int i=1;i<=n;i++) {
        if (!vis[i]||vis1[i]) continue;
        cnt++;
        if (cnt>2) return 0;
        dfs0(i,0);
    }
    return 1;
}

void dfs(int i,int d) {
    if(d==k) {
        if (!check()) return;
        int t=0;
        for (int u=1;u<=n;u++) {
            int s=N;
            for (int v=1;v<=n;v++) {
                if (!vis[v]) continue;
                s=min(s,dis(u,v));
            }
            t=max(t,s);
        }
        ans=min(ans,t);
        return;
    }
    if (i==n+1) return;
    dfs(i+1,d);
    vis[i]=1;
    dfs(i+1,d+1);
    vis[i]=0;
}


int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while (T--) {
        cin>>n>>k;
        for (int i=1;i<n;i++) {
            int u,v; cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        ans=N;
        dfs1(1,0);
        dfs2(1,1);
        dfs(1,0);
        cout<<ans<<'\n';
        for (int i=1;i<=n;i++) {
            hson[i]=0;
            e[i].clear();
        }
    }
    return 0;
}

