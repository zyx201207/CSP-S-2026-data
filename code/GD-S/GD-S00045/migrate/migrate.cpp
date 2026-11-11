#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],ans,dp[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n<=5000){
			for(int i=1;i<n;i++){
				memset(dp,0,sizeof(dp));
				dp[0][i]=1;
				int step=1;
				while(true){
					int l=i,r=i,sum=0;
					for(int j=i;j<=n;j++){
						while(x[l]+d<x[j]){
							sum-=dp[step-1][l];
							l++;
						}
						if(dp[step-1][j]==0){
							dp[step][j]=sum;
							if(dp[step][j]==2){
								ans++;
							}
						}
						r++;
						sum+=dp[step-1][j];
					}
					if(dp[step][n]!=0||step>n){
						break;
					}
					step++;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
