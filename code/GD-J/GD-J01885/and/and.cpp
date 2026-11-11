#include <bits/stdc++.h>

using namespace std;
long long n, m;
long long a[200005];
//long long k[200005];
//long long maxn = -1;
//
//void dfs(long long j) {
//	if (j == m) {
//		long long maxm = k[0];
//		for (long long i = 1; i < m; i++) {
//			maxm &= k[i];
//		}
//		maxn = max(maxn, maxm);
//		return;
//	}
//	for (long long i = j; i < n; i++) {
//		k[j] = a[i];
//		return dfs(j + 1);
//	}
//}

int main ( ) {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	cout << a[n - m];
//	dfs(0);
//	cout << maxn;
	return 0;
}
