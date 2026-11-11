#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[500010],b[500010],sum[500010],maxn=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(LL i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(LL i=1;i<n;i++)b[i]=a[i+1]-a[i];
    for(LL i=2;i<=n;i++)sum[i]=b[i-1]+sum[i-1];
    LL d=0,j=1;
    for(LL i=2;i<=n;i++){
        d+=b[i-1]*(i-j);
        while(d>m&&j<i){
            d-=sum[i]-sum[j];
            j++;
        }
        maxn=max(maxn,i-j+1);
    }
    cout<<maxn<<endl;
    return 0;
}
