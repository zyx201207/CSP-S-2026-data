#include<bits/stdc++.h>

#define int long long
#define pb push_back

const int N=1000005;

int c,T;
int n,k;
int u,v;
std::vector<int> g[N];
int rt;
int fa[N],dep[N];

void dfs(int u){
    for(int v:g[u]){
        if(v==fa[u]) continue;
        dep[v]=dep[u]+1;
        fa[v]=u;
        dfs(v);
    }
    return;
}

int mxd[N];
int col[N];
int deg[N];

void mrk(int u){
    mxd[u]=0;
    for(int v:g[u]){
        if(v==fa[u]) continue;
        fa[v]=u;
        mrk(v);
        mxd[u]=std::max(mxd[u],mxd[v]+1);
    }
    return;
}

int mt[N];

int par[N];
int vis[N];

int rs=0;
int a[N],ac;
int b[N];

void solve(int u){
    for(int v:g[u]){
        if(v==fa[u]) continue;
        fa[v]=u;
        solve(v);
    }
    if(!vis[u]&&deg[u]==2){
        ac=0;
        int now=u;
        while(deg[now]==2){
            vis[now]=1;
            a[++ac]=mt[now];
            now=fa[now];
        }
        a[0]=a[ac+1]=0;
        for(int i=0;i<=ac+1;i++) b[i]=ac+1;
        for(int i=1;i<=ac;i++){
            if(i-a[i]>0) b[i-a[i]-1]=std::min(b[i-a[i]-1],i+a[i]);
        }
        for(int i=ac;i>=0;i--) b[i]=std::min(b[i],b[i+1]);
        for(int i=0;i<ac;i++) rs=std::max(rs,b[i]-i-1);
    }
    return;
}

void run(){
    std::cin>>n>>k;
    for(int i=1;i<=n;i++){
        g[i].clear();
        fa[i]=mxd[i]=dep[i]=col[i]=deg[i]=mt[i]=par[i]=vis[i]=a[i]=b[i]=0;
    }
    for(int i=1;i<n;i++){
        std::cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int md=0,mdp=0;
    dep[1]=0; dfs(1);
    for(int i=1;i<=n;i++) if(dep[i]>md) md=dep[i],mdp=i;
    dep[mdp]=0; fa[mdp]=0;
    dfs(mdp);
    md=mdp=0; for(int i=1;i<=n;i++) if(dep[i]>md) md=dep[i],mdp=i;
    int L=md; rt=mdp;
    for(int i=0;i<L/2;i++) rt=fa[rt];

    int al=0,ar=L/2;
    while(al<ar){
        int am=(al+ar)>>1;

        dep[rt]=0;
        fa[rt]=0; mrk(rt);

        int all=0;
        for(int i=1;i<=n;i++) col[i]=mxd[i]>=am,deg[i]=0,all+=col[i];
        for(int i=1;i<=n;i++) for(int j:g[i]) deg[i]+=col[j];

        int nrt=0;
        for(int i=1;i<=n;i++){
            mt[i]=0;
            if(deg[i]==1&&col[i]) nrt=i;
            else if(deg[i]==2){
                for(int v:g[i]){
                    if(col[v]) continue;
                    mt[i]=std::max(mt[i],mxd[v]+1);
                }
                mt[i]=am-mt[i];
            }
        }

        for(int i=1;i<=n;i++) vis[i]=0;
        fa[nrt]=0;
        rs=0,solve(nrt);
        if(all-rs<=k) ar=am;
        else al=am+1;
    }
    std::cout<<al<<'\n';
    return;
}

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(0),std::cout.tie(0);

    std::cin>>c>>T;
    while(T--) run();

    return 0;
}
