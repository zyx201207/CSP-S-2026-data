#include<bits/stdc++.h>
#define int long long
using namespace std;

const int max_n = 2e5 + 5;
const int max_m = 50 + 5;

int n, m, ans = 0;
int a[max_n], b[max_m], vis[max_n];

vector<vector<int>> x(max_n * max_m);

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 0; j <= 31; j++) {
			if (a[i] & (1 << j)) {
				b[j]++;
			}
			else {
				x[j].push_back(i);
			}
		}
	}
	
	for (int i = 31; i >= 0; i--) {
		if (b[i] >= m) {
			ans += 1 << i;
			for (int j : x[i]) {
				if (vis[j]) continue;
				for (int k = 0; k <= 31; k++) {
					if (a[j] & (1 << k)) {
						b[k]--;
					}
				}
				vis[j] = 1;
			}
		}
	}
	
	cout << ans;
	
	return 0;
}