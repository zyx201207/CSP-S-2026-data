#include<iostream>
#include<algorithm>
using namespace std;
int n, ans = 1, c[500005];
long long m, a[500005], b;
bool cmp (long long a, long long b) {
	return a < b;
}
int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) scanf ("%lld", &a[i]);
	sort (a+1, a + n +1, cmp);
	c[1] = 1;
	for (int i = 2; i <= n; i++) {
		c[i] = c[i -1] +1;
		b += c[i -1] * (a[i] - a[i -1]);
		if (b > m) {
			b -= a[i] - a[i - c[i] +1];
			c[i]--;
		}
		ans = max (ans, c[i]);
	}
	cout << ans;
	return 0;
}
