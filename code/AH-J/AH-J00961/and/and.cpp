#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[200005];
ll f[200005];
ll dp[200005];//dp[i][j]:前i个数选择j个的最大值
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(ll j=1;j<=m;j++){
        for(ll i=1;i<=n;i++){
            f[i]=dp[i];
            if(j!=1)dp[i]=max(dp[i-1],(f[i-1]&a[i]));
            else dp[i]=max(dp[i-1],a[i]);
        }
    }
    printf("%lld",dp[n]);
    return 0;
}
