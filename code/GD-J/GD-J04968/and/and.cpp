#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	bool flag = true;
	int and_end = INT_MAX,maxn = INT_MIN;
	cin >> n >> m;
	vector<int>a(n+1);
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		if(!(a[i]+1)&a[i])flag = false;
		and_end&=a[i];
		maxn = max(maxn,a[i]);
	}
	if(flag) {
		sort(a.begin(),a.end());
		cout<<a[n-m+1]<<endl;
		return 0;
	}
	if(n==m) {
		cout<<and_end<<endl;
		return 0;
	}
	if(m==1) {
		cout<<maxn<<endl;
		return 0;
	}
	vector<vector<int>>dp(n+1,vector<int>(m+1,0));
	for(int i=1; i<=n; i++)dp[i][0]=a[i];
	dp[0][0] = a[1];
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=min(i,m); j++) {
			dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}
