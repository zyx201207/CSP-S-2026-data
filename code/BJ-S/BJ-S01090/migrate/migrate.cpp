#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N = 2e6+5,M=2e6,Q=2e3+5;
int c,t,n;ll m,a[N],nxt[N],oc[N],dp[Q][Q],sm[Q][Q];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%lld",&n,&m);
        for(int i = 1;i<=n;i++)scanf("%lld",&a[i]);
        int r = 1;
        for(int i = 1;i<=n;i++){
            while(r+1<=n&&a[i]+m>=a[r]&&a[r+1]<=a[i]+m)r++;
            nxt[i]=r;
        }ll ans = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++)dp[i][j]=1e9;
            dp[i][i]=0,sm[i][i]=1;
            for(int j = i;j<=n;j++){
                for(int k =j+1;k<=nxt[j];k++){
                    if(dp[i][k]>dp[i][j]+1)sm[i][k]=0;
                    dp[i][k]=min(dp[i][k],dp[i][j]+1);
                    if(dp[i][j]+1==dp[i][k])sm[i][k]+=sm[i][j];
                }if(sm[i][j]==2)ans++;
                //printf("%d ",sm[i][j]);
            }
            //printf("\n");
            
        }
        printf("%lld\n",ans);
    }
    
}