#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2020202],dp[500][500],f[500][500],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ans=0;
		memset(x,0,sizeof(x));
		memset(dp,60,sizeof(dp));
		memset(f,0,sizeof(f));
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(int j=2;j<=n;j++){
			for(int i=j-1;i>=1;i--){
				if(x[j]-x[i]<=d){
					dp[i][j]=1;
					f[i][j]=1;
				}
				else{
					for(int k=2;k<=j;k++){
						if(dp[i][k]+dp[k][j]<dp[i][j]){
							dp[i][j]=dp[i][k]+dp[k][j];
							f[i][j]=min(f[i][k]*f[k][j],3ll);
						}
						else if(dp[i][k]+dp[k][j]==dp[i][j]){
							f[i][j]=min(f[i][j]+f[i][k]*f[k][j],3ll);
						}
					}
					if(f[i][j]==2){
						ans++;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
