#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    long long l=0,r=n+1,f=0;
    while(l+1<r){
        long long mid=(l+r)/2;
        for(long long i=1;i<=n-mid+1;i++){
            long long sum=0;
            for(long long j=i;j<=i+mid-1;j++){
                sum+=(a[j]-a[j-1])*(j-i);
            }
            if(sum<=m){
                f=1;
                break;
            }
        }
        if(f==1){
            l=mid;
        }else{
            r=mid;
        }
        f=0;
    }
    cout<<l;
    return 0;
}
