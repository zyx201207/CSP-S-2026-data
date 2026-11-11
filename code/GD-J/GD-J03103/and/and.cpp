#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],dp[20005][20005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int max1=0;
	for(int i=1;i<=n;i++){
		max1=max(max1,a[i]);
		dp[i][1]=max1;
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		}
	}
	cout<<dp[n][m];
	return 0;
}
