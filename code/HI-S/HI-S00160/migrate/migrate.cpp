#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c, t, n, d;
int a[N], b[N], v[N];
bool tf(int x, int y) {
	return 0;
}
vector<int> idx;
void solve () {
	idx.push_back(0);
	int ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		int tt = 0;
		cin >> a[i];
		if (a[i]-a[idx[tt]] > d) {
			idx.push_back(i-1);
			tt++;
		}
	}
	if (n < 4) {
		cout << 0 << "\n";
		return;
	}
	for (int i = 4; i <= n; i++) {//每个子段 
		int f = i / 2;
		for (int j = 2; j <= f; j++) {//路径数 
			if (tf(i, j)) ans++;
		}
	}
	cout << ans << "\n";
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) solve();
	return 0;
}
