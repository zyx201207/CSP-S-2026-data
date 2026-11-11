#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
using ll = long long;
int n, lst[N], f[N], lstt[N], g[N], s[N];
ll d, a[N];
void Solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		lst[i] = i;
		for (int j = i + 1; j <= n; ++j) {
			if (a[j] - a[i] <= d) lst[i] = j;
			else break;
		}
		for (int j = i - 1; j >= 1; --j) {
			if (a[i] - a[j] <= d) lstt[i] = j;
			else break;
		}
	}
	int res = 0;
	for (int st = 1; st <= n; ++st) {
		for (int en = st + 3; en <= n; ++en) {
			for (int i = 0; i <= en + 1; ++i) f[i] = g[i] = s[i] = 0;
			f[st] = 1;
			int pos = st;
			while (pos < en) {
				if (pos == lst[pos]) break;
				for (int i = pos + 1; i <= min(lst[pos], en); ++i) f[i] = f[pos] + 1;
				pos = min(lst[pos], en);
			}
			g[st] = 1;
			vector<pair<int, int> > v;
			v.emplace_back(st, 0);
			for (int i = st + 1; i <= en; ++i) {
				if (f[i] > f[i-1]) {
					v[v.size() - 1].second = i-1;
					v.emplace_back(i, 0);
				}
			} v[v.size() - 1].second = en;
			pos = 0;
			for (int i = v[0].first; i <= v[0].second; ++i) g[i] = 1, s[i] = s[i-1] + 1;
			if (v.size() > 1) {
				for (int i = v[1].first; i <= en; ++i) {
					while (pos + 1 < v.size() && lstt[i] > v[pos].second) ++pos;
					g[i] = s[v[pos].second] - s[lstt[i] - 1];
					s[i] = s[i-1] + g[i];
				}
			}
			int flag = 0;
			for (int i = st; i <= en; ++i)
				flag |= (f[i] == 0);
			if (flag) continue;
			res += (g[en] == 2);
		}
	}
	cout << res << '\n';
	for (int i = 1; i <= n; ++i) lst[i] = f[i] = 0;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	int problem_id, T;
	cin >> problem_id >> T;
	while (T--) Solve();
	return 0;
}
/*

0 3
6 3
0 1 2 3 4 7
8 3
0 1 2 4 8 10 11 13
1 3
0



*/
