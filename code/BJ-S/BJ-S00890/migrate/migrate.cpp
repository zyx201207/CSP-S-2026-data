#include<bits/stdc++.h>
using namespace std;
const int N=510;
int C,T,n,dp[N][N],inf=1e8,cnt[N][N];
long long d,p[N],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&C,&T);
    while(T--){
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;++i){
            scanf("%lld",&p[i]);
        }
        for(int i=1;i<n;++i){
            for(int j=i+1;j<=n;++j){
                dp[i][j]=dp[j][i]=inf;
                cnt[i][j]=cnt[j][i]=0;
            }
        }
        for(int i=1;i<n;++i){
            for(int j=i+1;j<=n;++j){
                if(p[j]-p[i]>d){
                    break;
                }
                dp[i][j]=dp[j][i]=cnt[i][j]=cnt[j][i]=1;
            }
        }
        for(int k=1;k<=n;++k){
            for(int i=1;i<n;++i){
                if(i==k) continue;
                for(int j=i+1;j<=n;++j){
                    if(j==k) continue;
                    if(dp[i][j]>dp[i][k]+dp[k][j]){
                        dp[i][j]=dp[j][i]=dp[i][k]+dp[k][j];
                        int tmp=cnt[i][k]*cnt[k][j];
                        if(tmp>3) tmp=3;
                        cnt[i][j]=cnt[j][i]=tmp;
                    }
                    else if(dp[i][j]==dp[i][k]+dp[k][j]){
                        int tmp=cnt[i][j]+1;
                        if(tmp>3) tmp=3;
                        cnt[i][j]=cnt[j][i]=tmp;
                    }
                }
            }
        }
        ans=0;
        for(int i=1;i<n;++i){
            for(int j=i+1;j<=n;++j){
                if(cnt[i][j]==2){
                    ++ans;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
