#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 10;
long long n, m, a[MAX], mx = 0;
void dfs(long long d, long long p, long long sum) {
	if (d == m) {
		mx = max(mx, sum);
		return;
	}
	for (int i = p; i <= n; ++i) {
		dfs(d + 1, i, a[i] & i);
	}
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	dfs(0, 1, 0);
	cout << mx;
	return 0;
}
