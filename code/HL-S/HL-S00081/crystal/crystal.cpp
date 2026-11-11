#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 100;
int n, m, k, t = 1, ans, mid;
int a[N], b[N];
int sum, mi = INT_MAX;

int main() {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort (a + 1,a + n + 1);
	for (int i = 1; i <= n; i ++) sum += a[i];
	sum /= n;  
	for (int i = 1; i <= n; i ++) {
		b[i] = abs(a[i] - sum);
		if (b[i] < mi) {
			mi = b[i];
			mid = i;
		}
	}
	for (int i = 1; i < n; i ++) {
		while (1) {
			if (k >= m || mid - t == 0) break;
			k += a[mid] - a[mid-t];
			a[mid-t] = a[mid];
			t ++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[mid]) {
			ans ++;
		}
	}
	cout << ans;
	
	return 0;
}
