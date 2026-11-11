#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int ll[500005], rr[500005];
vector<int> b[500005];
int f, l[500005], vis[500005];
int n, m, a[500005], c[500005], ans[500005];
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i < n && a[i + 1] > a[i]) f = 1;
	}
	if (!f) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) l[j] = 0;
			for (int j = 1; j <= m; j++) c[j] = 0;
			for (int j = 1; j <= n; j++) vis[j] = 0;
			int k = 0;
			for (int j = i; j <= n; j++) {
				if (l[a[j]]) {
					ll[++k] = l[a[j]];
					rr[k] = j - 1;
				}
				l[a[j]] = j;
			}
			for (int j = 1; j <= k; j++) {
				for (int t = ll[j]; t <= rr[j]; t++) {
					vis[t] = 1;
				}
			}
			for (int j = i; j <= n; j++) {
				if (!vis[j]) c[a[j]] = 1;
			}
			for (int j = 1; j <= m; j++) ans[j] += c[j];
		}
	} else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) vis[j] = 0;
			for (int j = 1; j <= m; j++) c[j] = 0;
			for (int j = i; j <= n; j++) {
				int x = 0;
				for (int t = i; t < j; t++) {
					if (a[t] == a[j] && !vis[t]) {
						x = t;
						break;
					}
				}
				if (!x) continue;
				for (int t = x; t < j; t++) vis[t] = 1;
			}
			for (int j = i; j <= n; j++) {
				if (!vis[j]) c[a[j]] = 1;
			}
			for (int j = 1; j <= m; j++) {
				ans[j] += c[j];
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		if (i > 1) cout << " ";
		cout << ans[i];
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int T = 1;
//	cin >> T;
	while (T--) solve();
	return 0;
}

