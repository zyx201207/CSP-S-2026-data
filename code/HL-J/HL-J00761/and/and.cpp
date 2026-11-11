#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=2e5+10;
ll n,k,a[N];
inline bool cmp(ll x,ll y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    ll y;
    for(register int i=1; i<=n;i++){
        scanf("%lld",&a[i]);
        if(i==1) y=a[1];
        else y=y&a[i];
    }
    if(k==1){
        printf("0");
        return 0;
    }
    if(k==n){
        printf("%lld",y);
        return 0;
    }
    sort(a+1,a+1+n,cmp);
    ll ans=a[1];
    for(register int i=2; i<=k;i++){
        ans=ans&a[i];
    }
    printf("%lld",ans);
    return 0;
}
