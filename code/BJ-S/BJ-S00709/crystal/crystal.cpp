#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005];
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
    long long ans=1;
    for(long long i=1;i<=n;i++){
        long long l=1,r=i-1,as=-1;
        while(l<=r){
            long long mid=(l+r)/2;
            if(a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m){
                as=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        if(as!=-1){
            ans=max(ans,i-as+1);
        }
    }
    printf("%lld",ans);
    return 0;
}