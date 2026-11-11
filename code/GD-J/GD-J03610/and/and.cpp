#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long n, a[N], ans, m, p[N][35], vis[N];
void sol(long long id, long long x) {
	long long cur = 0;
	while (x) {
		p[id][++cur] = (x & 1);
		x >>= 1;
	}
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
		sol(i, a[i]);
		vis[i] = 1;
	}
	for (long long i = 30; i >= 1; i--) {
		bool bz = 1;
		long long sum = 0;
		for (long long j = 1; j <= n; j++) sum += (vis[j] && p[j][i]);
		if (sum >= m) {
			ans += pow(2, i - 1);
			for (long long j = 1; j <= n; j++) vis[j] = (vis[j] && p[j][i]);
		}
	}
	cout << ans;
	return 0;
}
