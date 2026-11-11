#include<bits/stdc++.h>
using namespace std;
long long a[2000005],dp[5005],dis[5005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    scanf("%d%d",&c,&T);
    while(T--){
        int n;
        long long d;
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        long long ans=0;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[j]=1e18;
                dp[j]=0;
            }
            dis[i]=0;
            dp[i]=1;
            for(int j=i-1;j>=1;j--){
                for(int k=j+1;k<=i;k++){
                    if(a[k]-a[j]>d){
                        break;
                    }
                    dis[j]=min(dis[j],dis[k]+1);
                }
                for(int k=j+1;k<=i;k++){
                    if(dis[j]==dis[k]+1 && a[k]-a[j]<=d){
                        dp[j]+=dp[k];
                    }
                }
            }
            for(int j=1;j<i;j++){
                if(dp[j]==2){
                    ans++;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}