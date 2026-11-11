#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e5+10;
LL n,m,a[N],dp[N],sum[N];
bool cmp(const LL &x,const LL &y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(LL i=1;i<=n;i++){
        scanf("%lld",a+i);
        sum[i]=sum[i-1]&a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(m==1) cout<<a[1];
    else if(m==n) cout<<sum[n];
    else{
        dp[1]=a[1];
        for(LL i=2;i<=n;i++) dp[i]=max({sum[i],dp[i-1]&a[i]});
        cout<<dp[m];
    }
    return 0;
}
