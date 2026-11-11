#include <bits/stdc++.h>
using namespace std;

const int kMaxN = 2 * 1e5 + 5;
long long a[kMaxN], f[kMaxN];
int n, m;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i ++) {
//		for (int i = 1; i <= m; i ++) cout << f[i] << " ";
//		cout << "\n";
		for (int j = m; j >= 1; j --) {
			if (j == 1) {
				f[j] = max(f[j], a[i]);
			} else f[j] = max(f[j], (f[j - 1] & a[i]));
		}
	}
	cout << f[m];
	return 0;
}
