#include<bits/stdc++.h>
using namespace std;
long long n,m,c,t,a[10000000];
long long dp[5005][5005][2],ans[5005][5005],s[5005][5005],sum=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
			dp[i][i][0]=dp[i][i][1]=0;
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				s[i][j]=a[j]-a[i];
				ans[i][j]=0;
				dp[i][j][0]=dp[i][j][1]=9999999999999999;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=i;k<j;k++){
					if(dp[i][k][0]>=s[k][j]){
						if(dp[i][k][1]==dp[i][j][1]){
							ans[i][j]++;
							dp[i][j][0]=max(dp[i][k][0]-s[k][j],dp[i][j][0]);
						}
						if(dp[i][k][1]<dp[i][j][1]){
							dp[i][j][1]=dp[i][k][1];
							dp[i][j][0]=dp[i][k][0]-s[k][j];
							ans[i][j]=1;
						}				
					}else{
						if(m>=s[k][j]){
							if(dp[i][k][1]+1==dp[i][j][1]){
								ans[i][j]++;
								dp[i][j][0]=max(m-s[k][j],dp[i][j][0]);
							}
							if(dp[i][k][1]+1<dp[i][j][1]){
								ans[i][j]=1;
								dp[i][j][0]=m-s[k][j];
							}
						}
					}
				}
				if(ans[i][j]==2)sum++;
			}
		}
		printf("%lld\n",sum);
		sum=0;
	}
	return 0;
}
