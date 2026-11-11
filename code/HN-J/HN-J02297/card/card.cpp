// lichenxi108.rp = inf, JCer.rp = -inf;
// 也许这是最后一战了。I won't AFO.
// 我该在哪里停留？我问我自己。

#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], lst[M], nxt[N], ans[N];
vector<int> v[M];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		v[a[i]].push_back(i);
		lst[a[i]] = i;
	}
	vector<vector<int> > cnt; 
	for (int i = 1; i <= n + 5; i++) {
		cnt.push_back({0});
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < int(v[i].size()) - 1; j++) {
			nxt[v[i][j]] = v[i][j + 1];
		}
	}
//	for (int i = 1; i <= n; i++) {
//		cout << nxt[i] << '\n';
//	}
	for (int i = 1; i <= m; i++) cnt[n + 1].push_back(0);
	for (int i = n; i >= 1; i--) {
		if (lst[a[i]] == i) {
			cnt[i] = cnt[i + 1];
			cnt[i][a[i]]++;
		}
		else cnt[i] = cnt[nxt[i]];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans[j] += cnt[i][j];
//			cout << cnt[i][j] << ' ';
		}
//		cout << '\n';
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
} 
