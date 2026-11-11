#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>2000){
		sort(a+1,a+n+1);
		int ans=7; 
		for(int i=n;i>=n-m+1;i--){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else{
		dp[1][1]=a[1];
		for(int i=2;i<=n;i++){
			dp[i][i]=dp[i-1][i-1]&a[i];
			dp[i][1]=max(dp[i-1][1],a[i]);
		}
		for(int i=3;i<=n;i++){
			for(int j=2;j<i;j++){
				dp[i][j]=max(dp[i-1][j],max(dp[i-1][j]&a[i],dp[i-1][j-1]&a[i]));
			}
		}
		cout<<dp[n][m];
	}
	return 0;
}
