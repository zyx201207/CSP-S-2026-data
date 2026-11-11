/**
 * @file CSP-S 2026
 *       Problem C. migrate
 * @author BJ-S01809
 *         LG-1014842 liuli688
 * @date 2026/10/31
*/
//password: Oct31==Dec25?

// Only one light!
// Onle One Light - Tatsh

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fst first
#define snd second
const int N = 2e6 + 10;
ll C, T, n, d, a[N], f[N], c[N];
ll g[N], ans;
deque<int> q;

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> C >> T;
	while (T--) {
		cin >> n >> d; ans = 0;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];//, cerr << c[i] << " \n"[i == n];
		if (C == 11 || C == 12) {
			if (n == 1 || d < (a[2] - a[1]) * 2 || d >= a[n] - a[1])
				cout << "0\n";
			else
				cout << max(0ll, n - 2 * (d / (a[2] - a[1]))) + 1 << '\n';
			continue;
		}
		if (C == 13 || C == 14) {
			for (int i = 4; i <= n; ++i)
				if (a[i] - a[i - 3] > d && a[i] - a[i - 1] <= d && a[i - 1] - a[i - 3] <= d && a[i] - a[i - 2] <= d && a[i - 2] - a[i - 3] <= d)
					++ans;
			cout << ans << '\n';
			continue;
		}
		for (int i = 1; i <= n; ++i) {
			f[i] = 0; g[i] = 1; c[0] = 1; q.push_back(i);
			for (int j = i + 1; j <= n; ++j) {
				while (q.size() && a[j] - a[q.front()] > d)
					c[f[q.front()]] -= g[q.front()], q.pop_front();
				if (q.empty())
					break;
				f[j] = f[q.front()] + 1;
				g[j] = c[f[j] - 1];
				ans += g[j] == 2;
				while (q.size() && f[q.back()] > f[j])
					c[f[q.back()]] -= g[q.back()], q.pop_back();
				q.push_back(j); c[f[j]] += g[j];
			}
			while (q.size())
				c[f[q.front()]] -= g[q.front()], q.pop_front();
			// cerr << i << '\n';
			// for (int j = i; j <= n; ++j)
			// 	cerr << f[j] << " \n"[j == n];
			// for (int j = i; j <= n; ++j)
			// 	cerr << g[j] << " \n"[j == n];
		}
		cout << ans << '\n';
	}
	return 0;
}

// 跌落重来便是 启程就无悔

// 如果没有结局的故事 能够被延续的话

//56pts