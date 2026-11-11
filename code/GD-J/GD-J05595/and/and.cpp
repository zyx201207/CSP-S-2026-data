#include <bits/stdc++.h> 
using namespace std;
int a[200010] = {};
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int maxx = -1;
	if (m == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j && a[i] and a[j] > maxx) maxx = a[i] and a[j];
			}
		}
	} else if (m == 1) {
		sort(a, a + n);
		maxx = a[n - 1];
	} else if (m == n) {
		maxx = a[0];
		for (int i = 1; i < n - 1; i++) {
			maxx = maxx and a[i];
		}
	} else if (m == n - 1) {
		for (int i = 0; i < n; i++) {
			if (i != n - 1) maxx = a[i + 1];
			else maxx = a[0];
			for (int j = 0; j < n; j++) {
				if (j != i && j != i + 1 && maxx == a[i + 1]) {
					maxx = maxx and a[j];
				} else if (j != i && j != 0) {
					maxx = maxx and a[j];
				}
			}
		}
	} else {
		sort(a, a + n);
		maxx = a[m - 1];
	}
	cout << maxx;
	return 0;
}
