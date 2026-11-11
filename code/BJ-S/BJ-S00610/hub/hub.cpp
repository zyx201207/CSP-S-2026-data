#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int c, t, n, k, f[N], dep[N], p[N], cnt, fa[N][25], dis[N], vis[N];
struct aaa{
    int v, w;
};
vector<int> g[N];
vector<aaa> g2[N];
int lca(int u, int v){
    if(u==v) return u;
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=24;i>=0;i--){
        if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
    }
    for(int i=24;i>=1;i--){
        if(fa[u][i]!=fa[v][i]) u=fa[u][i];
    }
    return fa[u][0];
}
int mt(int st){
    dis[st]=0;
    int res=0;
    for(int k=1;k<=cnt;k++){
        int now=0, mi=1e18+5;
        for(int i=1;i<=cnt;i++){
            if(!vis[i]&&dis[i]<mi){
                mi=dis[i];
                now=i;
            }
        }
        res+=dis[now];
        for(int i=0;i<g2[now].size();i++){
            int v=g2[now][i].v, w=g2[now][i].w;
            dis[v]=min(dis[v],dis[now]+w);
        }
    }
    return res;
}
void dfs(int u, int fa, int x){
    int cnt=0;
    f[u]=0x3f;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==fa) continue;
        cnt++;
        dfs(v,u,x);
        f[u]=min(f[v]-1,f[u]);
    }
    if(cnt==0){
        f[u]=x;
    }
    if(f[u]<=0){
        p[++cnt]=u;
        f[u]=x*2;
    }
}
bool chk(int x){
    cnt=0;
    for(int i=1;i<=n;i++) dis[i]=1e18, vis[i]=0;
    dfs(1,0,x);
    if(f[1]>=k) p[++cnt]=1;
    for(int i=1;i<=cnt;i++){
        for(int j=1;j<i;j++){
            int l=lca(p[i],p[j]);
            int w=dep[l]-dep[p[i]]+1+dep[l]-dep[p[j]]+1;
            g2[p[i]].push_back({p[j],w});
            g2[p[j]].push_back({p[i],w});
        }
    }
    if(mt(p[1])<=k) return 1;
    else return 0;
}
void dfs2(int u, int faa){
    dep[u]=dep[faa]+1;
    fa[u][0]=faa;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v!=faa) dfs2(v,u);
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        for(int i=1;i<=n;i++){
            g[i].clear();
            g2[i].clear();
        }
        for(int i=1;i<n;i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs2(1,0);
        for(int j=1;j<25;j++){
            for(int i=1;i<=n;i++){
                fa[i][j]=fa[fa[i][j-1]][j-1];
            }
        }
        int l=0, r=n-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(chk(mid))r=mid-1;
            else l=mid+1;
        }
        cout << l << endl;
    }
    return 0;
}
