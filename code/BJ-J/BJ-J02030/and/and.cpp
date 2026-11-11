#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m, a[200001], h, maxh = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (j == i) break;
			h = a[i] & a[j];
			if (h > maxh) {
				maxh = h;
			}
		}
	}
	cout << maxh;
	return 0;
}