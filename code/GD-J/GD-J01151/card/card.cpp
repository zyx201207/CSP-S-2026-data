#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 5e5 + 5;

int n, m, a[N], lst[N], cnt[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], lst[a[i]] = i;
	for (int i = 1; i <= n; ++i) {
		int t = i;
//		if (a[i] == a[i + 1]) {
//			continue;
//		}
		while (t <= n) {
			// cout << i << ' ' << t << '\n';
			t = lst[a[t]];
			cnt[t]++, cnt[++t]--;
		}
	}
	for (int i = 1; i <= n; ++i) {
		cnt[i] += cnt[i - 1];
	}
	for (int i = 1; i <= m; ++i) {
		cout << cnt[lst[i]];
		if (i < m) cout << ' ';
	}
	return 0;
}
/*

3 1 2 1 3 2 3 1 2 1

     1    2    3
lst 10    9    7
1: 2 4 8
2: 3 6
3: 1 5

shu ju ruo xie no hack

*/
