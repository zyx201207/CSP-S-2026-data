#include<bits/stdc++.h>
using namespace std;
long long c,t,n[100001],d[100001],x[100001][2000002],k[100001];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    for(long long i=1;i<=t;i++){
        scanf("%lld%lld",&n[i],d[i]);
        for(long long j=1;j<=n[i];j++){
            scanf("%lld",&x[i][j]);
        }
        for(long long j=1;j<=n[i]-2;j++){
            if(x[i][j]+d[i]>x[i][j+2]) k[i]++;
        }
    }
    for(long long i=1;i<=t;i++){
        printf("%lld\n",k[i]);
    }
    return 0;
}
