#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=550000;
LL n,m,a[N],f[N];
LL ans=1;
bool dc=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]+a[i];
    }
    for(int i=2;i<n;i++){
        if(a[i]-a[i-1]!=a[i+1]-a[i]){
            break;
        }
        if(i==n-1){
            dc=1;
        }
    }
    if(dc){
        for(LL i=1;i<=n;i++){
            if((m+f[i])/i>=a[i]){
                ans=i;
            }
        }
    }else{
        for(LL i=0;i<n;i++){
            for(LL j=i+1+ans;j<=n;j++){
                if(((m+f[j]-f[i])/(j-i))>=a[j]){
                    ans=j-i;
                }
            }
        }
    }
    if(ans==1) ans=0;
    printf("%lld",ans);
    return 0;
}
