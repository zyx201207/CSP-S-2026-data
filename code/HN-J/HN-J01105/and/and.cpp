#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[5005],dp[5005][5005];
int main(){
	int n,m;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		dp[i][1]=max(dp[i-1][1],a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=i;j++){
			if(i==1&&j==1) continue;
			dp[i][j]=dp[i-1][j-1]&a[i];
			if(j<=i-1) dp[i][j]=max(dp[i][j],dp[i-1][j]);
		}
	}
	cout << dp[n][m] << '\n';
	return 0;
} 
