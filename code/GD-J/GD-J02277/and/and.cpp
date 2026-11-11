#include <bits/stdc++.h>
using namespace std;
const int f=1e4;int n,m;
int a[f],ans=-999999999;
int dp[f][f];
int main(){
	//内存可能会爆    dp[i][ans]=dp[1-1][ans];dp[i][1]=max(dp[i][1],a[i]);dp[i][ans+1]=dp[i][ans]&a
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			dp[i][j]=max(dp[i][j],dp[i-1][j]);
			dp[i][1]=max(dp[i][1],a[i]);
			dp[i][j+1]=(dp[i-1][j] & a[i]);
		}
	}
	cout<<dp[n][m]<<"\n";
	return 0;
}
