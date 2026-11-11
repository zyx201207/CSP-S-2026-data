#include<iostream>
#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;
long long a[500010],m,sum[500010];
int n,ans;
bool check(int len){
    double d;
    for(int i=len;i<=n;i++){
        d=1.0*(sum[i]-sum[i-len]+m)*1.0/(len*1.0);
        if(d-1.0*(a[i]*1.0)>-0.000000001)return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int l=1,r=n,mid;
    while(l<r){
        mid=(l+r+1)>>1;
        if(check(mid))ans=mid,l=mid;
        else r=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}