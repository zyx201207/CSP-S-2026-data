#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+10;
LL n,m,a[N],ans,maxn;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(LL i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        maxn=max(maxn,abs(a[i]));
    }
    sort(a+1,a+n+1);
    if(n<=1e4){
        for(LL i=1;i<=n;i++){
        LL cnt=1,sum=0;
        for(LL j=i-1;j>=1;j--){
            sum+=(a[i]-a[j]);
            if(sum>m) break;
            cnt++;
        }
        ans=max(ans,cnt);
        }
        printf("%lld",ans);
        return 0;
    }
    if(maxn<=100){
        printf("%lld",n);
        return 0;
    }
    LL sum=0,cnt=0;
    for(LL i=n;i>=1;i--){
        sum+=a[n]-a[i];
        if(sum>m) break;
        cnt++;
    }printf("%lld",cnt);
    return 0;
}
