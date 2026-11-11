#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=15;
int n,k,ans,dist[N][N];
bool flag[N],vis[N];
vector<int> g[N];
int calc(){
    int res=0;
    for(int i=1;i<=n;i++){
        int tt=n+1;
        for(int j=1;j<=n;j++){
            if(flag[j]){
                tt=min(tt,dist[i][j]);
            }
        }
        res=max(res,tt);
    }
    return res;
}
void dfs1(int u){
    vis[u]=true;
    for(int v:g[u]){
        if(flag[v] && !vis[v]){
            dfs1(v);
        }
    }
    return ;
}
bool check(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!vis[i] && flag[i]){
            cnt++;
            dfs1(i);
        }
    }
    return cnt<=2;
}
void dfs(int i,int choose){
    if(choose>k){
        return ;
    }
    if(i==n+1){
        memset(vis,false,sizeof vis);
        if(choose==k && check()){
            ans=min(ans,calc());
        }
        return ;
    }
    flag[i]=true;
    dfs(i+1,choose+1);
    flag[i]=false;
    dfs(i+1,choose);
    return ;
}
void solve(){
    cin >>n>>k;
    for(int i=1;i<=n;i++){
        g[i].clear();
        flag[i]=false;
    }
    memset(dist,0x3f,sizeof dist);
    for(int i=1;i<n;i++){
        int u,v;
        cin >>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        dist[u][v]=dist[v][u]=1;
        dist[i][i]=dist[i+1][i+1]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    ans=n+1;
    dfs(1,0);
    cout <<ans<<"\n";
    return ;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin >>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
