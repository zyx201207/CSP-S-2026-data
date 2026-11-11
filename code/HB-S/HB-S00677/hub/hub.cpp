#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=1e5+5,mod=998244353;
const ll inf=1e18;
int c,T,n,K,v[N],s;
vector<int> g[N];
int isk(int k){
    return (s>>(k-1))&1;
}
void bj(int p){
    v[p]=1;
    for(int i:g[p]){
        if(!v[i]&&isk(i)){
            bj(i);
        }
    }
}
ll dep[N];int fa[N][20];
void dfs(int p,int ft,int de){
    fa[p][0]=ft,dep[p]=de;
    for(int k=1;k<20;k++){
        fa[p][k]=fa[fa[p][k-1]][k-1];
    }
    for(int i:g[p]){
        if(i==ft) continue;
        dfs(i,p,de+1);
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    for(int k=19;k>=0;k--){
        if(dep[fa[u][k]]>=dep[v]){
            u=fa[u][k];
        }
    }
    if(u==v) return u;
    for(int k=19;k>=0;k--){
        if(fa[u][k]!=fa[v][k]){
            u=fa[u][k];
            v=fa[v][k];
        }
    }
    return fa[u][0];
}
ll dis(int u,int v){
    return dep[u]+dep[v]-2ll*dep[lca(u,v)];
}
void solve(){
    cin>>n>>K;
    for(int i=1;i<=n;i++){
        g[i].clear();
        v[i]=0;
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        for(int k=0;k<20;k++){
            fa[i][k]=0;
        }
        dep[i]=0;
    }
    dfs(1,0,1);
    ll ans=inf;
    for(s=0;s<(1<<n);s++){
        int cnt=0;ll res=0;
        for(int i=1;i<=n;i++){
            v[i]=0;
        }
        for(int k=1;k<=n;k++){
            if(isk(k)) cnt++;
        }
        if(cnt>K) continue;
        cnt=0;int fl=1;
        for(int k=1;k<=n;k++){
            if(!v[k]&&isk(k)){
                bj(k);
                cnt++;
                if(cnt>2){
                    fl=0;
                    break;
                }
            }
        }
        if(!fl) continue;
        for(int i=1;i<=n;i++){
            if(!isk(i)){
                ll mn=inf;
                for(int j=1;j<=n;j++){
                    if(isk(j)){
                        mn=min(mn,dis(i,j));
                    }
                }
                res=max(res,mn);
            }
        }
        ans=min(ans,res);
        // cout<<"\n";
    }
    // cout<<dis(2,3)<<" ";
    // cout<<"\n";
    cout<<ans<<"\n";
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    fastio
    cin>>c>>T;
    while(T --) solve();
    return 0;
}
/*
g++ hub.cpp -o d
./d

*/