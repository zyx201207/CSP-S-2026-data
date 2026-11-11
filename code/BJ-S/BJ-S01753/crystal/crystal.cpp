#include<bits/stdc++.h>
using namespace std;
int n,ans,tot;
long long m,a[500005],d[500005],sum,r;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    if(n>5000){
        r=a[2]-a[1];
        for(int i=2;i<=n;i++){
            sum+=(i-1)*r;
            if(sum>m){
                printf("%d",i-1);
                return 0;
            }
        }
        printf("%d",n);
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
         sum=0,tot=0;
         for(int j=1;j<=n;j++) d[j]=a[i]-a[j];
         for(int j=n;j>=1;j--){
            if(d[j]<0){
                tot++;
                 continue;
            }
            sum+=d[j];
            if(sum>m){
                ans=max(ans,(n-tot)-j);
                break;
            }
            else if(j==1) ans=max(ans,n-tot);
         }
    }
    printf("%lld",ans);
    return 0;
}
