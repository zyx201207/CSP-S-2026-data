#include <iostream>
using namespace std;
#define Write cin.tie(nullptr);
#define by cout.tie(nullptr);
#define ___NightDay___ ios::sync_with_stdio(0)
#define N 200005
#define inf 0x3f3f3f3f

int n, m, a[N], maxa = -inf, cnt[15];
int ans = -inf, ds[N];
void dfs(int stp, int last) {
	if (stp > m) {
		int res = 0x7fffffff;
		for (int i = 1; i <= m; i ++) {
			res &= a[ds[i]];
		}
		ans = max(ans, res);
	}
	for (int i = last + 1; i <= n; i ++) {
		ds[stp] = i;
		dfs(stp + 1, i);
	}
	return;
}

int main() {
	Write by ___NightDay___;
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		maxa = max(a[i], maxa);
	}
	if (m == 1) {
		int tmax = -inf;
		for (int i = 1; i <= n; i ++) {
			tmax = max(tmax, a[i]);
		}
		cout << tmax;
		return 0;
	}
	if (m == 2) {
		int ans = -inf;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				if (i == j) {
					continue;
				}
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	if (m == n) {
		int ans = 0x7fffffff;
		for (int i = 1; i <= n; i ++) {
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	if (maxa <= 4) {
		for (int i = 1; i <= n; i ++) {
			cnt[a[i]] ++;
		}
		if (cnt[4] >= m) {
			cout << 4;
		} else if (cnt[3] >= m) {
			cout << 3;
		} else if (cnt[2] >= m) {
			cout << 2;
		} else if (cnt[2] + cnt[3] >= m) {
			cout << 2;
		} else if (cnt[1] >= m) {
			cout << 1;
		} else if (cnt[1] + cnt[3] >= m) {
			cout << 1;
		} else {
			cout << 0;
		}
		return 0;
	}
	dfs(1, 0);
	cout << ans;
	return 0;
}
// 60pts, #1~10 + #16, 17
