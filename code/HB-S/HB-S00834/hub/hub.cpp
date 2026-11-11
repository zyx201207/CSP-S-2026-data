#include<bits/stdc++.h>
using namespace std;
vector<int> ad[1000005];
int c,t,n,k;
int f[1000005][22];
int dep[1000005];
void dfs(int u,int p){
    dep[u]=dep[p]+1;
    f[u][0]=p;
    for(int i=1;i<22;i++){
       f[u][i]=f[f[p][i-1]][i-1];
    }
    for(int v:ad[u]){
        if(u!=v) dfs(v,u);
    }
    return;
}
int lca(int u,int v){
    if(dep[u]>dep[v]) swap(u,v);
    for(int i=22;i>=0;i--){
        if(dep[v]-(i<<1)>dep[u]) f[v][i]=f[v][i+1];    
    }
    
    return f[u][0];
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        int u,v;
        for(int i=1;i<n;i++){
            cin>>u>>v;
            ad[u].push_back(v);
            ad[v].push_back(u);
        }
    }
}