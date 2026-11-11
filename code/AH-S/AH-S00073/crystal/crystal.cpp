#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10;
LL n,m,a[N],d[N],ans,s;
bool check(LL x){
    for(LL j=1;j<=n-x+1;j++){
        LL r=j+x-1,s=0;
        for(LL k=j;k<=r;k++){
            s+=(d[k]*(k-j));
        }
        if(s<=m) return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(LL i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(LL i=1;i<=n;i++) d[i]=a[i]-a[i-1];
    d[1]=0;
    LL sum=0;
    bool ok=1;
    for(LL i=2;i<=n;i++){
        sum+=d[i]*(i-1);
        if(i!=n&&d[i]!=d[i+1]) ok=0;
    }
    if(sum<=m) printf("%lld",n);
    else if(ok){
        for(LL i=2;i<=n;i++){
            if(d[i]*(i-1)<=m) m-=d[i]*(i-1),ans=i;
        }
        printf("%lld",ans);
    }
    else{
        LL l=1,r=n+1;
        while(l<r){
            LL mid=(l+r)/2;
            if(check(mid)) l=mid+1;
            else r=mid;
        }
        printf("%lld",l-1);
    }
    return 0;
}


