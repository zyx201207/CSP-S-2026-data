#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[200005],vis[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;
    ll a[200005];
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        dp[1]=max(dp[1],a[i]);
    }for(ll i=1;i<=n;i++){
    if(a[i]==dp[1]){
        vis[i]=1;
        break;
    }
    }
    for(ll i=2;i<=n;i++){
            ll viss=0;
        for(ll j=1;j<=n;j++){
            if(!vis[j]){
                if(dp[i-1]&a[j]>dp[i]){
                        viss=j;
                    dp[i]=max(dp[i],dp[i-1]&a[j]);
                }
            }
        }
        vis[viss]=1;
    }cout<<dp[m];
    return 0;
}
