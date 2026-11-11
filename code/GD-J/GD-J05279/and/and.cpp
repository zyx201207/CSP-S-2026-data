#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	long long a[n+2]={};
	long long dp[n+2][m+2]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=m;i++){
		dp[0][i]=1073741823;
	}
	for(int i=0;i<=n;i++){
		dp[i][0]=1073741823;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m&&j<=i;j++){
			dp[i][j]=dp[i-1][j-1]&a[i];
			for(int d=1;d<=i;d++){
				dp[i][j]=max(dp[i][j]&a[i],dp[i-d][j-1]&a[d]);
			}
		}
	}
	cout<<dp[n][m];
	return 0;
}
