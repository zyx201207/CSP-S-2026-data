#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int a[N];
int t[31];
int f[N][31];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) {
		int p = a[i];
		int idx = 0;
		while (p) {
			f[i][idx] = p % 2;
			t[idx++] += p % 2;
			p >>= 1;
		} 
	}
	int ans = 0;
	for (int i = 30; i >= 0; --i) {
		if (t[i] >= m) {
			int cnt = 0;
			for (int j = n; j >= 1; --j) {
				if (f[j][i]) {
					ans = (ans == 0 ? a[j] : ans & a[j]);
					++cnt;
				}
				if (cnt == m) break;
			}
			cout << ans << '\n';
			return 0;
		}
	}
	cout << ans << '\n';
	return 0;
}
