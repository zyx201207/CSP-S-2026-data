#include <bits/stdc++.h>
using namespace std;
long long a[2000005],dp[2][2000005],n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		dp[0][i]=max(dp[0][i-1],a[i]);
	}
	for(int i=2;i<=m;i++){
		for(int j=i;j<=n;j++){
			dp[1][j]=max(dp[0][j-1]&a[j],dp[1][j-1]);
		}
		for(int j=1;j<=n;j++){
			dp[0][j]=dp[1][j];
		}
	}
	cout << dp[0][n];
	return 0;
} 
