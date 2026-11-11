#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005],ty,v[1000005],ans[1000005],sz[1000005],t[1000005];
vector<int> w[1000005];
void dfs(int x,int fa){
    sz[x]=1;
    for(auto it:w[x]){
        if(it==fa)continue;
        dfs(it,x);
        sz[x]+=sz[it];
    }
    ans[a[x]]+=sz[x]*t[x];
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i>=1;i--){
        if(v[a[i]]){
            w[v[a[i]]].push_back(i);
        }else{
            w[i+1].push_back(i);
            t[i]=1;
        }
        v[a[i]]=i;
    }
    dfs(n+1,0);
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
