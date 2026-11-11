#include <bits/stdc++.h>
using namespace std;

long long a[200005], n, m, maxn;
bool b[55];

void dfs(long long x) {
	if (x == n + 1) {
		long long cnt = 0, sum = 0;
		for (long long i = 1; i <= n; i++) {
			if (b[i]) cnt++;
		}
		if (cnt == m) {
			bool flag = 0;
			for (long long i = 1; i <= n; i++) {
				if (b[i]) {
					if (!flag) {
						flag = 1;
						sum = a[i];
					} else sum &= a[i];
				}
			}
			maxn = max(maxn, sum);
		}
		return;
	}
	b[x] = 0;
	dfs(x + 1);
	b[x] = 1;
	dfs(x + 1);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) cin >> a[i];
	if (n < 21) {
		dfs(1);
		cout << maxn;
	} else {
		sort(a + 1, a + n + 1);
		if (m == 1) cout << a[n];
		else if (m == n) {
			maxn = a[1];
			for (long long i = 2; i <= n; i++) maxn &= a[i];
			cout << maxn;
		} else if (m == 2 && n < 2001) {
			for (long long i = 1; i <= n; i++) {
				for (long long j = i + 1; j <= n; j++) maxn = max(maxn, a[i] & a[j]);
			}
			cout << maxn;
		} else {
			maxn = a[n];
			for (long long i = n - 1; i > n - m; i--) maxn &= a[i];
			cout << maxn;
		}
	}
	return 0;
}
