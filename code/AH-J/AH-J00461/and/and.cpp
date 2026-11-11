#include <iostream>
#include <algorithm>
using namespace std;
long long n, m, a[5000010], b[5000010];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
		for (long long j = 1; j <= m; j++) {
			b[j] = a[i] & a[j];
		} 
	}
	long long ans = 0;
	for (long long i = 1; i <= n; i++) {
		ans = max(ans, b[i]);
	}
	cout << ans;
	return 0;
}
