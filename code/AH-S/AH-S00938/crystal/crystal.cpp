#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[500010],maxn=-0x7ffffffff;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(LL i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    if(n>5000){
        LL sum=0,pos=0;
        for(LL i=n-1;i>=1;i--){
            sum+=a[n]-a[i];
            if(sum>m){
                pos=n-i;
                break;
            }
        }
        printf("%lld",pos);
    }
    else{
        sort(a+1,a+n+1);
        LL l=1,r=1;
        while(l<=r&&r<=n){
            LL sum=0;
            for(LL i=r;i>=l;i--){
                sum+=a[r]-a[i];
            }
            if(sum<=m){
                if(r-l+1>maxn){
                    maxn=r-l+1;
                }
                r++;
            }
            if(sum>m){
                l++;
            }
        }
        printf("%lld",maxn);
    }

    return 0;
}
