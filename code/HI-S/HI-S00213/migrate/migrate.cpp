#include <bits/stdc++.h>
using namespace std;

long long c, t, n, d, a[2000005];

int minn, sum;
void dfs(int u, int v, int pos, int l) {
	if (l > minn) return;
	if (pos == v) {
		if (l < minn) {
			minn = l;
			sum = 1;
		}
		else sum++;
		return;
	}
	for (int i = pos+1; i <= v; i++) {
		if (a[i] - a[pos] <= d) dfs(u, v, i, l+1);
		else return;
	}
}

int main() {
	freopen("migrate.in",  "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	while (t) {
		t--;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int ans = 0;
		for (int i = 1; i < n; i++) {
			for (int j = i+1; j <= n; j++) {
				if (a[j] - a[i] <= d) continue;
				minn = INT_MAX;
				sum = 0;
				dfs(i, j, i, 0);
				if (sum == 2) ans++;
			}
		}
		cout << ans << endl;
	}
}
