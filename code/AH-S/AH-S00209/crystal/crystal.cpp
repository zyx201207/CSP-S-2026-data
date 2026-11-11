#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m;
LL a[500010];
LL sum[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    LL ans=1;
    LL l,r,mid;
    for(int i=1;i<=n;i++){
        l=1,r=i;
        while(l<r){
            mid=(l+r)/2;
            if(a[i]*(i-mid+1)-sum[i]+sum[mid-1]<=m){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        ans=max(ans,i-l+1);
    }
    printf("%lld",ans);
    return 0;
}
