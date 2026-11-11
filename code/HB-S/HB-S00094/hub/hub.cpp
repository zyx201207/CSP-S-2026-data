#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+6;
int c,n,k,de[N],ans,maxd;
vector<int>e[N];
void init(){
    for(int i=1;i<=n;i++)e[i].clear();
}
void dfs(int u,int fa){
    if(de[u]>maxd){
        maxd=de[u];
        ans=u;
    }
    for(int v:e[u]){
        if(v==fa)continue;
        de[v]=de[u]+1;
        dfs(v,u);
    }
}
void solve(){
    cin>>n>>k;
    init();
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    de[1]=1,maxd=1;
    dfs(1,0);
    de[ans]=1,maxd=1;
    dfs(ans,0);
    if(maxd-k==1)maxd++;
    cout<<((maxd-k)>>1)<<"\n";
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>c>>t;
    while(t--)solve();
    return 0;
}
