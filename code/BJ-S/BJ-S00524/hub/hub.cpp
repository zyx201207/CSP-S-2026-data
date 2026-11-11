#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,k,u,v,ans,dep[N],f[22][N];
vector<int> g[N];
bool vis[N];
void ddfs(int u,int fa){
    for(int v:g[u]){
        if(v==fa) continue;
        f[0][v]=u;
        dep[v]=dep[u]+1;
        ddfs(v,u);
    }
}
void init(){
    for(int i=1;i<=20;i++)
        for(int j=1;j<=n;j++)
            f[i][j]=f[i-1][f[i-1][j]];
}
int lca(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=20;i>=0;i--) if(dep[f[i][u]]>=dep[v]) u=f[i][u];
    if(u==v) return u;
    for(int i=20;i>=0;i--){
        if(f[i][u]!=f[i][v]){
            u=f[i][u];
            v=f[i][v];
        }
    }
    return f[0][u];
}
void solve(){
    int res=0,q,d;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        q=1e9;
        for(int j=1;j<=n;j++){
            if(!vis[j]) continue;
            d=lca(i,j);
            q=min(q,dep[i]+dep[j]-2*dep[d]);
            //cout<<i<<' '<<j<<' '<<d<<'\n';
        }
        res=max(res,q);
    }
    ans=min(ans,res);
}
void dfs2(int p,int u){
    if(p==k+1){
        solve();
        return;
    }
    vis[u]=1;
    for(int v:g[u])
        if(!vis[v]) dfs2(p+1,v);
    vis[u]=0;
}
void dfs(int p,int u){
    if(p==k+1){
        solve();
        return;
    }
    vis[u]=1;
    for(int v:g[u])
        if(!vis[v]) dfs(p+1,v);
    for(int i=1;i<=n;i++)
        if(!vis[i]) dfs2(p+1,i);
    vis[u]=0;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;ans=1e9;
        for(int i=1;i<=n;i++) vis[i]=0,g[i].clear();
        for(int i=1;i<n;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(k==n){
            cout<<0<<'\n';
            continue;
        }if(k==n-1){
            cout<<1<<'\n';
            continue;
        }
        dep[1]=1;
        ddfs(1,0);
        init();
        for(int i=1;i<=n;i++) dfs(1,i);
        cout<<ans<<'\n';
    }
    return 0;
}
/*往事如流云般悄然逝去，我不敢再奢望与我擦肩而过的世界都能被记起。
极悲处不悲，极喜处不喜。恰是淡色的事物最能勾起回忆。
临此高阁，晓望夕风，不觉一年秋思又入梦里。*/