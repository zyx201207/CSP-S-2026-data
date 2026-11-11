#include<bits/stdc++.h>
#define r (l+len-1)
using namespace std;
int c,t,n,dp[5005][5005];
long long cnt[5005][5005],ans=0;
long long d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;++i){
			scanf("%lld",&x[i]);
		}memset(dp,0x3f,sizeof(dp));
        memset(cnt,0,sizeof(cnt));
        ans=0;
        for(int i=1,zl=1,zr=1;i<=n;++i){
			while(x[zl]<x[i]-d)++zl;
			while(zr+1<=n&&x[zr+1]<=x[i]+d)++zr;
			for(int j=zl;j<i;++j){
                dp[j][i]=1;
                cnt[j][i]=1;
            }for(int j=i+1;j<=zr;++j){
                dp[i][j]=1;
                cnt[i][j]=1;
            }
		}for(int len=2;len<=n;++len){
            for(int l=1;r<=n;++l){
                long long div=1;
                for(int k=l+1;k<r;++k){
                    if(dp[l][k]+dp[k][r]<dp[l][r]){
                        dp[l][r]=dp[l][k]+dp[k][r];
                        cnt[l][r]=cnt[l][k]*cnt[k][r];
                        div=dp[l][r]-1;
                    }else if(dp[l][k]+dp[k][r]==dp[l][r]){
                        cnt[l][r]+=cnt[l][k]*cnt[k][r];
                    }
                }cnt[l][r]/=div;
                if(cnt[l][r]==2)++ans;
            }
        }
        printf("%lld\n",ans);
	}
	return 0;
}