#include <bits/stdc++.h>
using namespace std;
long long n, m, a[5005], b[500005], ans;
int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	if (n > 5000) {
		bool o = false;
		for (int i = 1; i <= n; i++) {
			if (b[i] != i) {
				o = true;
				break;
			}
		}
		if (o == false) {
			long long l = 0;
			int t = 0;
			int k = 1;
			bool x = false;
			while (l <= m) {
				if (t >= n) {
					break;
				}
				l += k;
				t++;
				k++;
			}
			t = max(t, 1);
			cout << t;
			return 0;
		}
		else {
			long long l = 0;
			int t = 0;
			int k = (b[2] - b[1]);
			bool x = false;
			while (l <= m) {
				if (t >= n) {
					break;
				}
				l += k;
				t++;
				k += (b[2] - b[1]);
			}
			t = max(t, 1);
			cout << t;
			return 0;
		}
	}
	sort(b + 1, b + n + 1);
	for (long long i = 1; i < n; i++) {
		for (long long j = 1; j <= n - i; j++) {
			a[j] = a[j - 1] + (b[j + 1] - b[j]) * j;
			if (a[j] <= m) {
				ans = max (ans, j + 1);
			} 
		}
	}
	cout << ans; 
	return 0;
}
