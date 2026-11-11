#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
long long x[505];
long long cnt[505][505];
long long dp[505][505];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int ti=1;ti<=t;ti++){
		scanf("%d%lld",&n,&d);
		if(n>500){
			return 0;
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<=n;i++){
			cnt[i][i]=1;
		}
		for(int len=1;len<n;len++){
			for(int i=1;i+len<=n;i++){
				int j=i+len;
				dp[i][j]=1e9;
				cnt[i][j]=0;
				if(x[j]-x[i]<=d){
					dp[i][j]=1;
					cnt[i][j]=1;
					continue;
				}
				for(int k=i+1;k<j;k++){
					if(dp[i][k]+dp[k][j]<dp[i][j]){
						dp[i][j]=dp[i][k]+dp[k][j];
						cnt[i][j]=cnt[i][k]*cnt[k][j];
					}
					else if(dp[i][k]+dp[k][j]==dp[i][j]){
						cnt[i][j]+=cnt[i][k]*cnt[k][j];
					}
				} 
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2){
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
