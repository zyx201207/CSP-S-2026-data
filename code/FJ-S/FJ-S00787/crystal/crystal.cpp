#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+1];
	long long b[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	long long dp[n+1][m+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[j]=abs(a[i]-a[j]);
		}
		for(int l=0;l<=n;l++){
			dp[l][0]=0;
		}
		for(int l=0;l<=m;l++){
			dp[0][l]=0;
		}
		for(int l=1;l<=n;l++){
			for(int k=1;k<=m;k++){
				if(b[l]==0){
					dp[l][k]=0;
				}else if(k>=b[l]){
					int x=dp[l-1][k-b[l]]+b[l];
					int y=dp[l-1][k];
					dp[l][k]=max(x,y);
				}else{
					dp[l][k]=dp[l-1][k];
				}
			}
		}
		long long cnt=0;
		for(int j=m;j>1;j--){
			if(dp[n][j]!=dp[n][j-1]){
				cnt++;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans+1;
	return 0;
}
