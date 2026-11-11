#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k,ans;
vector<int>tr[1005];
int a[1005],b[1005],vis[1005];
void dfs(int u,int fa){
    vis[u]=1;
    for(int v:tr[u]){
        if(b[v]&&v!=fa)dfs(v,u);
    }
}
bool check(){
    for(int i=1;i<=n;i++)vis[i]=0;
    int sum=0;
    for(int i=1;i<=k;i++){
        if(!vis[a[i]]){
            sum++;
            dfs(a[i],0);
        }
        if(sum>2)return 0;
    }
    return 1;
}
int dfs1(int u,int fa,int dep){
    if(b[u])return dep;
    int deep=1e18;
    for(int v:tr[u]){
        if(v==fa)continue;
        deep=min(deep,dfs1(v,u,dep+1));
    }
    return deep;
}
int d(int x){
    return dfs1(x,0,0);
}
int solve1(){
    int x=0;
    for(int i=1;i<=n;i++){
        x=max(x,d(i));
    }
    return x;
}
void solve(int t){
    if(t==k){
        if(check()){
            ans=min(ans,solve1());
        }
        return;
    }
    for(int i=a[t]+1;i<=n;i++){
        a[t+1]=i;
        b[i]=1;
        solve(t+1);
        b[i]=0;
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=1e18;
        cin>>n>>k;
        for(int i=1;i<=n;i++)tr[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            tr[u].push_back(v);
            tr[v].push_back(u);
        }
        solve(0);
        cout<<ans<<"\n";
    }
    return 0;
}
