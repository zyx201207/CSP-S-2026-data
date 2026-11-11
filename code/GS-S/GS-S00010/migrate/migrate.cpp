#include<bits/stdc++.h>
using namespace std;
int c,t,n;long long d,a[2000005],f[200005],s,g[200005];


int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%lld",&n,&d);s=0;
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        for(int i=1;i<n-1;i++){
            memset(g,0,sizeof(g));memset(f,0x7f,sizeof(f));
            f[i]=0;g[i]=1;
            for(int j=i+2;j<=n;j++){
                for(int k=j-1;k>=i;k--){
                    if(a[j]-a[k]>d)break;
                    if(f[k]+1<f[j])f[j]=f[k]+1,g[j]=g[k];
                    else if(f[k]+1==f[j])g[j]+=g[k];
                }if(g[j]==2)++s;
            }
        }
        printf("%lld\n",s);
    }
    return 0;
}
