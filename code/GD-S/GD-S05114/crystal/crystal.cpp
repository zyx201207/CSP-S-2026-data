#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
using ll = long long;
int n;
ll m,a[N];
int dp[N][N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++){
		dp[i][i] = 1;
	}
	for(int len = 2; len<=n; len++) {
		for(int l = 1; l+len-1<=n; l++) {
			int r = l + len - 1;
			ll num = 0;
			dp[l][r] = max(dp[l][r-1],dp[l+1][r]);
			int left = l;
			while(left!=r) {
				num+=a[r]-a[left];
				left++;
			}
			if(num<=m) dp[l][r]++;
		}
	}
	cout<<dp[1][n];
	return 0;
}
