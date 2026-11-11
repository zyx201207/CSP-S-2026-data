#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int a[N], ans[N];
bool ck[N];
int c, t;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--) {
		memset(ans, 0, sizeof(ans));
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		ck[1] = 1;
		for (int i = 1; i <= n; i++) {
			if (a[i]) {
				for (int j = a[i] + 1; j <= a[i] + d && j <= a[n]; j++) {
					if (ck[j]) ans[j]++;
					ck[j] = true;
				}
			}
		}
		int mx = 0;
		for (int i = 1; i <= a[n]; i++) {
			if (ans[i] >= mx)
				mx = ans[i];
		}
		cout << mx << "\n";
	}
	return 0;
} 

