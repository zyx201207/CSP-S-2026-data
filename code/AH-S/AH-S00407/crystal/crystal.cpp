#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10;
LL a[N],n,m,sum[N];
bool check(LL x){
    LL M=1e18;
    for(LL j=x;j<=n;j++){
        LL s=sum[j]-sum[j-x];
        M=min(M,a[j]*x-s);
    }
    return M<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(LL i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    LL minn=1e18,p=0;
    bool f=0;
    for(LL i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        if(i==2) p=a[i]-a[i-1];
        else if(i>2){
            if(a[i]-a[i-1]!=p) f=1;
            p=a[i]-a[i-1];
        }
        minn=min(minn,a[i]-a[i-1]);
    }
    if(minn>m){
        cout<<1;
        return 0;
    }
    if(!f){
        for(LL i=1;i<n;i++){
            m-=p*i;
            if(m==0){
                cout<<i+1;
                return 0;
            }
            if(m<0){
                cout<<i;
                return 0;
            }
        }
    }
    /*for(LL i=n;i>=1;i--){
        for(LL j=i;j<=n;j++){
            LL ans=sum[j]-sum[j-i];
            if(a[j]*i-ans<=m){
                cout<<i;
                return 0;
            }
        }
    }*/
    LL l=1,r=n,ans=1;
    while(l<=r){
        LL mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
