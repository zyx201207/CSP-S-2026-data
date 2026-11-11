#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	if (n <= 500 && m <= 200) {
		int top = 0;
		vector<int> ans(m + 1);
		for (int i = 0; i < n; ++i) {
			top = 0;
			vector<int> stk(2 * n), cnt(m + 1), pos(m + 1);
			for (int j = i; j < n; ++j) {
				if (cnt[a[j]]) {
					for (int k = pos[a[j]] + 1; k <= top; ++k) cnt[stk[k]]--;
					top = pos[a[j]];
				} else {
					stk[++top] = a[j];
					pos[a[j]] = top;
					cnt[a[j]]++;
				}
			}
			for (int i = 1; i <= top; ++i) {
				ans[stk[i]]++;
			}
		}
		for (int i = 1; i <= m; ++i) {
			cout << ans[i] << " ";
		}
		return;
	}		
	vector<int> ans(m + 1), cnt(m + 1, 0), pos(m + 1, 0), del(m + 1), last(m + 1, 0);
	vector<bool> vis(n);
	for (int i = n - 1; i >= 0; --i) {
		if (cnt[a[i]]) {
			for (int j = i + 1; j < last[a[i]]; ++j) {
				if (!vis[j]) del[a[j]]++;
				if (!vis[j] && cnt[a[j]] - del[a[j]] == 0) ans[a[j]] += pos[a[j]] - i;
				vis[j] = true;
			}
		}
		if (cnt[a[i]] <= del[a[i]]) pos[a[i]] = i;
		last[a[i]] = i;
		cnt[a[i]]++;
	}
	for (int i = 1; i <= m; ++i) {
		if (cnt[i] - del[i] > 0) ans[i] += pos[i] + 1;
	}
	
	for (int i = 1; i <= m; ++i) {
		cout << ans[i] << " ";
	}
}

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}

