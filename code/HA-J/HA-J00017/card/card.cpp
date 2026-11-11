#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v[300005];
int bit[500005 << 4], rp[300005], a[500005];
void build(int x, int l, int r)
{
	if (l == r) {
		bit[x] = rp[a[l]];
		return;
	}
	int mid = (l + r) / 2;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
	bit[x] = max(bit[x << 1], bit[x << 1 | 1]);
}
int query(int x, int l, int r, int L, int R) 
{
	if (L <= l && r <= R) {
		return bit[x];
	}
	if (l > R || L > r) {
		return -1;
	}
	int mid = (l + r) / 2;
	return max(query(x << 1, l, mid, L, R), query(x << 1 | 1, mid + 1, r, L, R));
}
signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		rp[a[i]] = i;
	}
	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i - 1, res = i;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (query(1, 1, n, mid, i - 1) > i) {
				l = mid + 1;
			} else {
				r = mid - 1;
				res = mid;
			}
		}
//		if (a[i] == 1) {
//			cout << res << ' ' << i << '\n';
//		}
		v[a[i]].push_back({res, i});
	}
	for (int i = 1; i <= m; i++) {
//		cout << i << ": \n";
		int ans = 0;
		sort(v[i].begin(), v[i].end());
		int l = 0, r = -1;
		for (int j = 0; j < v[i].size(); j++) {
//			cout << v[i][j].first << ' ' << v[i][j].second << '\n';
			if (v[i][j].first > r) {
				ans += r - l + 1;
				l = v[i][j].first;
				r = v[i][j].second;
			} else {
				r = max(v[i][j].second, r);
			}
		}
		ans += r - l + 1;
		cout << ans << ' ';
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/