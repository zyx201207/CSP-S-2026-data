#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,ans=0;
ll a[200005],vis[200005];
void dfs(ll cnt,ll s){
    if(cnt>=m){
        ans=max(s,ans);
        return;
    }
    for(ll i=0;i<n;i++){
        if(vis[i]==0){
            ll s1=s&a[i];
            vis[i]=1;
            dfs(cnt+1,s1);
            vis[i]=0;
        }
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll xxx=0;
    cin>>n>>m;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        xxx=max(a[i],xxx);
    }
    if(m==1){
        cout<<xxx;
        return 0;
    }else if(m==2){
        ll aaa=0;
        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                aaa=max(aaa,a[i]&a[j]);
            }
        }
        cout<<aaa;
        return 0;
    }else{
        for(ll i=0;i<n;i++){
            dfs(1,a[i]);
            vis[i]=1;
        }
        cout<<ans;
    }
    return 0;
}
