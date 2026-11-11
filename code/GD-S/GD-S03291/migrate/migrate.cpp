#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+10;
int n;
ll d, x[N];

inline int d1 (int i) {
	return x[i+1] - x[i];
}
inline int d2 (int i) {
	return x[i+2] - x[i];
}

int main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		int ans = 0;
		for (int k = 1; k <= n-2; k++) {
			if (d2(k) >= d) {
				int i = k, j = k+1;
				while (i > 1 && d1(i-1) <= d && d2(i-1) > d) {
					i--;
				} 
				while (j < n-2 && d1(j+1) <= d && d2(j+1) > d) {
					j++;
				}
				if (j == n-2 && d1(j) <= d && d2(j) > d) j++;
				if (j == n-1 && d1(j) <= d) j++;
				j = max(j, k+2);
				ans += (k - i) * (j - k - 1);
				cout << i << ' ' << j << ' ' << k << '\n';
			}
		}
		cout << ans << '\n';
	}
}
