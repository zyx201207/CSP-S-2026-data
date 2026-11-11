#include <bits/stdc++.h>
using namespace std;
long long ans,n,x,dp[2005][2005],a[200005],m,sum;

int main(){
	freopen("and.in","r",stdin);
 	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i  =1;i<=n;i++){
		cin >> a[i];
	}
	for(int i =1;i<=n;i++){
		dp[i][1] = max(a[i],dp[i-1][1]);
		
	}
	for(int i =2;i<=n;i++){
		for(int j =2;j<=i&&j<=m;j++){
			long long o =dp[i-1][j-1]&a[i];//xuan
			dp[i][j] = max(o,dp[i-1][j]);//
		}
	}
	cout << dp[n][m];
	return 0;

}
