#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005];
long long dp[5005][5005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    scanf("%lld %lld",&c,&t);
    while(t--){

        scanf("%lld %lld",&n,&d);
        memset(dp,0,sizeof(dp));
        memset(x,0,sizeof(x));
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }
        for(int len=2;len<=n;len++){

            for(int i=1;i<=n-len+1;i++){
                int j=i+len-1;
                int s=0;
                if(abs(x[i]-x[j])<=d){
                    dp[i][j]=1;
                    continue;
                }
                for(int k=j-1;k>i;k--){
                    if(k==0){
                        break;
                    }
                    s+=dp[i][k]*dp[k][j];
                }
                dp[i][j]=s;
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(dp[i][j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
