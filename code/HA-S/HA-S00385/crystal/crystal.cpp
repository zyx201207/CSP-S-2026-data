#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int n, m;
int a[N];
int dp[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	dp[0] = 0; a[0] = a[1];
	for (int i=1;i<=n;i++) {
		dp[i] = dp[i-1] + (i - 1) * (a[i] - a[i-1]);
		if (m >= dp[i-1] && m < dp[i]) {
			cout<<(i-1);
			return 0;
		}
	}
	cout<<n;
	return 0;
}
