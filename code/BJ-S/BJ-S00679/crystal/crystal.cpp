#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
ll n,m,a[MAXN],dp[MAXN];
bool check(int k){
    ll min_=INF;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+1ll*(a[i]-a[i-1])*min(i-1,k);
        if(i>k){
            dp[i]-=a[i]-a[i-k];
        }
        if(i>=k){
            min_=min(min_,dp[i]);
        }
    }
    return min_<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll l=1,r=n;
    while(l<=r){
        ll mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<l-1;
    return 0;
}