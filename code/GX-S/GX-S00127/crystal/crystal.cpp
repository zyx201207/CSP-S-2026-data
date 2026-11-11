#include<bits/stdc++.h>
using namespace std;
long long n,m,a[555555],f[555555],f2[555555],ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    f[0]=0;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    memset(f2,0,sizeof(f2));
    for(int i=1;i<n;i++) f2[i+1]=f2[i]+(a[i+1]-a[i])*(long long)i;
    f2[1]=0;
    for(int i=1;i<=n;i++){
        if(f2[i]!=f2[i-1])
            printf("[Changed]%d:+%lld(%lld-%lld)*%d(a:%lld %lld)\n",i,a[i]-a[i-1],a[i],a[i-1],i-1,f2[i],f2[i-1]);
    }
    for(int i=n;i>1;i--){
        if(m>=f2[i]){
            ans=i;
            break;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
//wait for bug fixed
//wrong test:4(10-12)
