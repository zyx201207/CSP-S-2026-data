#include<bits/stdc++.h>
using namespace std;
long long a[2000005],dp[2000005],dp1[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,m;
		long long ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[j]=LONG_LONG_MAX;
				dp1[j]=LONG_LONG_MAX;
			}
			dp[i]=0;
			dp1[i]=1;
			for(int j=i+1;j<=n;j++){
				for(int k=i;k<j;k++){
					//cout<<dp[j]<<" "<<dp[k]<<endl;
					if(a[j]-a[k]<=m){
						if(dp[j]>dp[k]+1 && dp[k]!=LONG_LONG_MAX){
							dp[j]=dp[k]+1;
							dp1[j]=dp1[k];
						}
						else if(dp[j]==dp[k]+1 && dp[k]!=LONG_LONG_MAX){
							dp1[j]+=dp1[k];
						}
					}
				}
			}
			for(int j=i+1;j<=n;j++){
				//cout<<dp[j]<<" "<<dp1[j]<<endl;
				if(dp1[j]==2 && dp[j]!=LONG_LONG_MAX){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
