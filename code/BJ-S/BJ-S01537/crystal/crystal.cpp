#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans;
ll a[500005],sum[500005];
bool check(ll x){
    for(int i = x;i <= n;i++){
        if((a[i]*x-sum[i]+sum[i-x]) <= m)return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i = 1;i <= n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++){
        sum[i] = sum[i-1]+a[i];
    }
    ll l = 1,r = n,mid;
    while(l <= r){
        mid = (l+r)/2;
        if(check(mid) == true){
            ans = mid;
           l = mid+1;
        }else{
            r = mid-1;
        }
    }
    printf("%lld",ans);
    return 0;
}
