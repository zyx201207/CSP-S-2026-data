#include <bits/stdc++.h>
#define int long long
using namespace std; 
const int N = 2e5 + 10;
int bit[N][31];
int n, m, a[N];
bool flag[N];
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 30; j >= 0; j--) {
			bit[i][j] = a[i] & (1LL << j); 
		}
	} 
	int tot = n;
	for (int i = 30; i >= 0; i--) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (bit[j][i] && !flag[j]) ++sum;
		}
		if (sum >= m) {
			for (int j = 1; j <= n; j++) {
				if (!bit[j][i]) flag[j] = true, --tot;
			}
		}
		if (tot == m) break;
	}
	int ans = -1;
	for (int i = 1; i <= n; i++) {
		if (!flag[i]) {
			if (ans == -1) ans = a[i];
			else ans &= a[i];
		}
	}
	cout << ans << '\n';
	return 0;
} 
