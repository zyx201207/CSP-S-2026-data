#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
bool check(long long mid){
    long long sum=0,str=a[0];
    for(int i=1;i<=mid;i++){
        if(a[i]==str)continue;
        else {
            sum+=(i-1)*(a[i]-str);
            str=a[i];
        }
    }
    if(sum<=m)return 1;
    for(int i=mid+1;i<=n;i++){
        sum-=(str-a[i-mid]);
        sum+=(mid-1)*(a[i]-str);
        str=a[i];
        if(sum<=m)return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);/*zhushi!!!!!!!!!!!*/
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    a[0]=a[1];
    long long l=1,r=n,res=1;
    while(l<=r){
        long long mid=(l+r)>>1;
        if(check(mid)){
            res=mid;
            l=mid+1;
        }else r=mid-1;
    }
    printf("%lld",res);

    return 0;
}
