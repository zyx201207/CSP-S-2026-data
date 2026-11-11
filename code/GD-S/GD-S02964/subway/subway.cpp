#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using LL = long long;
vector<vector<int>> t, stw, chs;//t[n][m]:time
vector<vector<bool>> wts;
vector<bool> vis;
vector<int> w;
int c, n, m, d, q, End, mn = INT_MAX, strw, st;
void dfs(int now, int time, int line) {
//	cout << now << " t " << time << " l " << line << endl;
	if (wts[line][End]) {
		mn = min(mn, time + t[line][End] + t[strw][st]);
//		cout << mn << "t " << time << "t " << t[line][End] << "t " << t[strw][st] << endl;
		return;
	} if (vis[now]) return;
	vis[now] = true;
	for (auto s : chs[line]) {
		for (auto w : stw[s]) {
			if (line == w) continue;
//			cout << s << " w " << w << " t " << t[line][s] << " t " << t[w][s] << endl;
			dfs(s, time + t[line][s] + t[w][s], w);
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	w.resize(n + 1);
	t.resize(n + 1);
	wts.resize(n + 1);
	stw.resize(m + 1);
	chs.resize(n + 1);
	vis.resize(m + 1);
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 0; i < n; i++) {
		t[i].resize(m + 1);
		wts[i].resize(m + 1);
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int ax, tx;
			cin >> ax >> tx;
			t[i][ax] = tx;
			stw[ax].push_back(i);
			wts[i][ax] = true;
		}
	} for (int i = 0; i < m; i++) {
		if (stw[i].size() > 1) {
			for (auto x : stw[i]) {
				chs[x].push_back(i);
			}
		}
	} while (q--) {
		cin >> st >> End;
		LL ans = w[st] + w[End];
//		cout << ans << endl;
		for (auto w : stw[st]) {
			strw = w;
			dfs(st, 0, w);
		} ans += mn;
//		cout << "mn" << mn << endl;
		cout << ans << endl;
//		cout << endl;
	}
}

