#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=7005,K=1e6+5;
int C,n,m,d,q,w[N],k,a[N],t[N],l,r,f[N][N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&C,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%lld",w+i);
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++){
        scanf("%lld",&k);
        for(int j=1;j<=k;j++) scanf("%lld%lld",a+j,t+j);
        for(int j=1;j<=k;j++){
            for(int l=1;l<=k;l++){
                f[a[j]][a[l]]=f[a[l]][a[j]]=min(f[a[j]][a[l]],t[j]+t[l]);
            }
        }
    }
    for(int i=1;i<=m;i++) f[i][i]=0;
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=i+1;j<=m;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--){
        scanf("%lld%lld",&l,&r);
        if(l>r) swap(l,r);
        printf("%lld\n",f[l][r]+w[l]+w[r]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
