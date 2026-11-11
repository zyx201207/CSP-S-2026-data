#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }

    sort(a+1,a+n+1);

    for(ll i=1;i<=n;i++){
        ll now=a[i];
        if(i+m-1>n){
            for(ll j=i;j>=i-m+1;j--){
                now&=a[j];
            }
        }
        else{
            for(ll j=i+1;j<=i+m-1;j++){
                now&=a[j];
            }
        }
        ans=max(ans,now);
    }

    printf("%lld",ans);
    return 0;
}
