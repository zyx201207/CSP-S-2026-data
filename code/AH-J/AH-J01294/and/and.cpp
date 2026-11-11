#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int g[N][35];
bool vis[N];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 31; j++) {
			if (a[i] & (1 << j)) {
				g[i][j] = 1;
			}
//			cout << g[i][j];
		}
//		cout << endl;
	}
	long long ans = 0;
	for (int i = 30; i >= 0; i--) {
		int base = 1 << i;
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (g[j][i] == 1 && !vis[j]) {
				cnt++;
			}
		}
		if (cnt >= m) {
			ans += base;
			for (int j = 1; j <= n; j++) {
				if (g[j][i] == 0 && !vis[j]) {
					vis[j] = true;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}

