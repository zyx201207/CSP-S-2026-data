#include<bits/stdc++.h>
using namespace std;
const long long N = 1e5 * 5 + 5;
long long n, m;
long long a[N];
long long b[N];
bool check(long long k) {
	long long sum = 0, s2 = 0;
	for (int i = 1; i < k; i++) {
		sum += b[i];
		s2 += b[i] * i;
	}
	if (s2 <= m) {
		return true;
	}
	for (int i = 2; i <= n - k; i++) {
		s2 -= sum;
		s2 += b[i + k - 2] * (k - 1);
		if (s2 <= m) {
//			cout << s2 << " " << i << "|\n";
			return true;
		}
		sum -= b[i - 1];
		sum += b[i + k - 2];
	}
	return false;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort (a + 1, a + n + 1);
	for (int i = 1; i < n; i++) b[i] = a[i + 1] - a[i];
	long long sum = 0;
	long long l = 0, r = n + 1;
	while (l + 1 < r) {
		long long mid = (l + r) >> 1;
		if (check(mid)) l = mid;
		else r = mid;
//		cout << l << " " << r << "\n";
	}
	cout << l;
	return 0;
}

