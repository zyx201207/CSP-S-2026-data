#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[500010],f[500010],f2[500010];

bool cmp(int x,int y){
    return x<y;
}

int main (){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1,cmp);
    for(int i=n-1;i>=1;i--){
        f[i]=a[i+1]-a[i];
    }
    for(int i=1;i<n;i++){
        f2[i]=f2[i-1]+f[i]*i;
    }

    // printf("f:");
    // for(int i=1;i<=n;i++){
    //     printf("%lld ",f[i]);
    // }
    // printf("\nd:");
    // for(int i=1;i<=n;i++){
    //     printf("%lld ",f2[i]);
    // }
    // printf("\nscanf OK!\n");

    ll i=0,j=0,sum=0,ans=0;
    while(i<n-1||j<n-1){
        if(sum>m||j==n-1){
            i++;
        }
        if(sum<=m&&j<n-1){
            ans=max(ans,j-i);
            j++;
            // if(ans<300) printf("ans=%lld\n",ans);
        }
        // if(i==0) sum=f2[j];
        // else 
        sum=f2[j]-f2[i]-i*(a[j+1]-a[i+1]);
        // if(ans<300) printf("way:%lld-%lld-%lld*(%lld-%lld)=%lld\n",f2[j],f2[i],i,a[j+1],a[i+1],sum);
        // if(ans<300) printf("i=%lld j=%lld sum=%lld\n",i,j,sum);
    }
    printf("%lld",ans+1);
    return 0;
}