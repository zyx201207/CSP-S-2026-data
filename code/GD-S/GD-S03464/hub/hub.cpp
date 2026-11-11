#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10,M=5e5+10;
int c,t,n,k;
int a[N];
vector<int> E[N];
int dis[N],f[N],son[N];
int maxdis,idx;
void dfs(int u,int fa){
    f[u]=fa;
    dis[u]=dis[fa]+1;
    son[u]=0;
    if(dis[u]>maxdis) {
        maxdis=dis[u];
        idx=u;
    }
    for(auto V:E[u]){
        if(V==fa) continue;
        dfs(V,u);
        son[u]++;
    } 
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) E[i].clear();
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1,0);
    maxdis=0;
    dfs(idx,0);
    int root=idx;
    for(int i=1;i<=maxdis/2;i++) root=f[root];
    dfs(root,0);
    cout<<(maxdis+k-1)/(k+1)<<"\n";
}
signed main(){
    freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--) {
        solve();
    }
}
