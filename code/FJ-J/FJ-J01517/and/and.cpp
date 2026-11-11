#include <bits/stdc++.h>
using namespace std;
const int N = 1e8 + 10;
int a[N];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if (m == 1) {
		int mx = -1;
		while (n--) {
			long long k;
			cin >> k;
			if (k > mx) {
				mx = k;
			}
		}
		cout << max(mx, 1);
		return 0;
	}
	if (m == 2) {
		int mx = -1;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					continue;
				}
				if ((a[i] & a[j]) > mx) {
					mx = (a[i] & a[j]);
				}
			}
		}
		cout << max(mx, 1);
		return 0;
	}
	if (m == n) {
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int sum = a[1];
		for (int i = 2; i <= n; i++) {
			sum = (sum & a[i]);
		}
		cout << max(sum, 1);
		return 0;
	}
	if (m == (n - 1)) {
		long long mn = 1e8;
		int flag = 0;
		int sum = a[1];
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] < mn) {
				mn = a[i];
				flag = i;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (i == flag) {
				continue;
			}
			sum = (sum & a[i]);
		}
		cout << max(sum, 1);
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int sum = a[n];
	for (int i = n; i > n - m; i--) {
		sum = (sum & a[i]);
	}
	cout << max(sum, 1);
	return 0;
}
