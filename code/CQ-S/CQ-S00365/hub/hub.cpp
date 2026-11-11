/***************
 - @GavinCQTD
***************/

#include <cassert>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

ifstream fin("hub.in");
ofstream fout("hub.out");

int c,t,n,k,hd[1000005],ecnt,fa[1000005][25];
struct{int to,nxt;} ed[2000005];

void adde(int u,int v){
    ed[++ecnt] = {v,hd[u]};
    hd[u] = ecnt;
}

void dfs(int u,int prt){
    fa[u][0] = prt;
    dep[u] = dep[prt]+1;
    for(int eid=hd[u];eid!=0;eid=ed[eid].nxt){
        int v=ed[eid].to;
        if(v==prt){
            continue;
        }
        dfs(v,u);
    }
}

int lca(int u,int v){
    if(dep[u]<dep[v]){
        swap(u,v);
    }
    for(int j=log2(n);j>=0;j--){
        if(dep[fa[u][j]]>=dep[v]){
            u = fa[u][j];
        }
    }
    if(u==v){
        return u;
    }
    for(int j=log2(n);j>=0;j--){
        if(fa[u][j]!=fa[v][j]){
            u = fa[u][j];
            v = fa[v][j];
        }
    }
    return fa[u][0];
}

void solve(){
    cin >> n >> k;
    for(int i=1;i<n;i++){
        int u,v;
        fin >> u >> v;
        adde(u,v);
        adde(v,u);
    }
    
    dfs(1,0);
    for(int j=1;j<=log2(n);j++){
        for(int i=1;i<=n;i++){
            fa[i][j] = fa[fa[i][j-1]][j-1];
        }
    }
    
    if(k==2){
        ll ans=1e18;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j||fa[i][0]==j||fa[j][0]==i){
                    continue;
                }
                ll cur=0;
                for(int k=1;k<=n;k++){
                    if(k==i||k==j){
                        continue;
                    }
                    cur = max(cur,min(dep[k]+dep[i]-2*dep[lca(k,i)],dep[k]+dep[j]-2*dep[lca(k,j)]));
                }
                ans = min(ans,cur);
            }
        }
        
        fout << ans << "\n";
    }
    
    ecnt = 0;
    for(int i=1;i<=n;i++){
        hd[i] = 0;
    }
}

int main(){
    fin >> c >> t;

    for(int i=1;i<=t;i++){
        solve();
    }
    
    return 0;
}


