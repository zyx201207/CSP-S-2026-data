#include<bits/stdc++.h>
using namespace std;
struct Node{
    long long sl;
    long long cd;
};
long long fw,t;
long long n,m;
long long a[2000005];
Node dp[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&fw,&t);
    for(long long u=1;u<=t;u++){
        scanf("%lld%lld",&n,&m);
        for(long long i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        sort(a+1,a+n+1);
        long long num=0;
        for(long long k=1;k<=n;k++){
            for(long long i=1;i<=n;i++){
                dp[i]={0,LLONG_MAX};
            }
            dp[k]={1,1};
            for(long long i=k+1;i<=k+m-1;i++){
                dp[i]={1,2};
            }
            for(long long i=m+k;i<=n;i++){
                if(a[i]-a[i-1]>m){
                    break;
                }
                for(long long j=i-1;j>=i-m;j--){
                    if(dp[j].cd+1<dp[i].cd){
                        dp[i]={dp[j].sl,dp[j].cd+1};
                    }else if(dp[j].cd+1==dp[i].cd){
                        dp[i]={dp[i].sl+1,dp[i].cd};
                    }
                }
            }
            for(long long i=k;i<=n;i++){
                if(dp[i].sl==2){
                    num++;
                }
            }
        }
        printf("%lld\n",num);
    }
    return 0;
}
