#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int dp[200005][2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int mmax=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mmax=max(mmax,a[i]);
		dp[i][1]=mmax;
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		}
	}
	cout<<dp[n][m];
	return 0;
}
