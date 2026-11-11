#include<bits/stdc++.h>
using namespace std;

long long n, m, a[200001];

void solveA() {
	sort(a + 1, a + 1 + n);
	printf("%lld\n", a[n - m + 1]);
	return;
}

void solve() {
	vector<long long>dp(n + 1);
	dp[n] = a[n];
	for (int i = n - 1; i >= 1; i--) {
		dp[i] = max(dp[i + 1], dp[i + 1] & a[i]);
	}
	printf("%lld\n", dp[1]);
	return;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	bool fA = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		if (a[i] % 2 == 0) {
			fA = 0;
		}
	}
	if (fA) {
		solveA();
	} else {
		solve();
	}
	return 0;
}
