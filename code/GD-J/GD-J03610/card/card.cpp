#include <bits/stdc++.h>
using namespace std;
const long long M = 3e5 + 5, N = 5e5 + 5, mod = 0;
int n, m, z[M], a[N], cur, ans, id, sum[N], mp[M];
vector<pair<int, int>> e[M];
unordered_map<int, int> js;
void sol() {
	for (int i = 1; i <= m; i++) z[i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) mp[j] = 0;
		int id = 0;
		for (int j = i; j <= n; j++) {
			if (!mp[a[j]] || mp[a[j]] > id) {
				sum[++id] = a[j];
				mp[a[j]] = id;
			} else {
				id = mp[a[j]];
			}
//			if (i == 6) {
//				for (int k = 1; k <= id; k++) cout << sum[k] << " ";
//				cout << '\n';
//			}
		}
//		for (int i = 1; i <= id; i++) cout << sum[i] << ' ';
//		cout << '\n';
		for (int j = 1; j <= id; j++) z[sum[j]]++;
	}
	for (int i = 1; i <= m; i++) cout << z[i] << ' ';
	exit(0);
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	bool ooo = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		z[a[i]] = i;
		if (a[i] < a[i - 1] && i > 1) ooo = 0;
	}
//	if (ooo) {
//		for (int i = 1; i <= m; i++) cout << i << ' ';
//		return 0;
//	}
	if (n <= 5000) sol();
	for (int i = 1; i <= n; i++) sum[i] = (i != z[a[i]] ? 0 : sum[i - 1] + 1);
//	for (int i = 1; i <= n; i++) cout << sum[i] << '\n';
	for (int j = 1; j <= m; j++) {
		int i = z[j];
		cur = sum[i - 1];
		if (cur) e[a[i]].push_back({i - cur, i - 1});
		e[a[i]].push_back({i, i});
	}
	for (int i = 1; i <= m; i++) {
		int k = e[i].size();
		ans = 0;
		for (int j = 0; j < k; j++) {
			if (e[i][j].first <= e[i][j - 1].first) e[i][j].first = e[i][j - 1].first + 1;
			ans += max(mod, e[i][j].second - e[i][j].first + 1LL);
		}
//		if (a[n] == i) ans = max(ans, n);
		cout << ans << ' ';
	}
	return 0;
}
