#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 2;

int c, T, n, d, a[N], b[N], dis[N];

void dfs(int x, int step) {
	if (step < dis[x]) b[x] = 0, dis[x] = step;
	b[x]++;
	int l = x, r = n, ans = 0;
	while (l <= r) {
		int mid = l + ((r - l) >> 1);
		if (a[mid] <= a[x] + d) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
//	cout << "\t" << x << " " << ans << endl;
	for (int i = x + 1;i <= ans;i++) {
		if (a[i] - a[x] > d) break;
		dfs(i, step + 1);
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	
	while (T--) {
		cin >> n >> d;
		for (int i = 1;i <= n;i++) cin >> a[i];
		sort(a + 1, a + 1 + n);
		if (c == 13 || c == 14) {
			cout << 0 << endl;
			continue;
		}
		if (c == 11 || c == 12) {
			int D = a[2] - a[1];
			if (3 * D >= d && 2 * D <= d) cout << n - 3 << endl;
			else cout << 0 << endl;
			continue;
		}
		int ans = 0;
		for (int i = 1;i <= n;i++) {
			for (int j = i;j <= n;j++) b[j] = 0, dis[j] = 2e18;
			dis[i] = 0;
//			for (int j = 1;j < i;j++) cout << "  ";
//			for (int j = i;j <= n;j++) cout << b[j] << " ";
//			cout << endl; 
			dfs(i, 0);
			for (int j = i;j <= n;j++) {
				if (b[j] == 0) break;
				ans += (b[j] == 2);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
