#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200010],ans,vis[200010];
void dfs(ll step,ll now,int x){
    if(step==m){
        ans=max(ans,now);
        return ;
    }
    if(x==n){
        return ;
    }
    vis[x]=1;
    for(int i=1;i<=n;i++) if(!vis[i])dfs(step+1,now&a[i],i);
    vis[x]=0;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) dfs(1,a[i],i);
    cout<<ans<<endl;
    return 0;
}
