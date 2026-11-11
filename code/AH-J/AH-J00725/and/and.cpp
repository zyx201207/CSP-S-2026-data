#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200010],ans;
void dfs(ll t,ll s,ll cnt){
    if(cnt>=m){
        ans=max(ans,s);
        return;
    }
    if(t>n){
        return;
    }
    dfs(t+1,s,cnt);
    dfs(t+1,s&a[t],cnt+1);
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,INT_MAX,0);
    cout<<ans;
    return 0;
}
