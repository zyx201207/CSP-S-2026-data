#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500007],b[500007];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1); //nlogn
    long long l=1,r=n;
    while(l<=r){
        long long mid=(l+r)>>1,sum=0;
        bool flag=0;
        for(int i=2;i<=mid;i++){
            sum+=(a[i]-a[i-1])*(i-1);
        }
        if(sum<=m) flag=1;
        for(int i=mid+1;i<=n;i++){
            sum-=(a[i-1]-a[i-mid]);
            sum+=(a[i]-a[i-1])*(mid-1);
            if(sum<=m){
                flag=1;
                break;
            }
        }
        if(flag) l=mid+1;
        else r=mid-1;
    }
    printf("%lld",r);
    return 0;
}
