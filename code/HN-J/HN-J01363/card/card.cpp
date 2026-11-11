#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kMaxN = 5e5 + 10, kInf = 1e18;

int a[kMaxN], ans[kMaxN], n, m, cnt, flag = 0;
int num[kMaxN], lst[kMaxN], tot;

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i], flag |= i > 1 || a[i] < a[i - 1];
	}
	if (!flag && n > 5000) {
		for (int i = 1, j = 1; i <= m; i++) {
			for (; a[j] < i; i++);
			if (a[j] == i) {
				cout << m - j + 1 << ' ';
			} else {
				cout << "0 ";
			}
		}
		return cout << '\n', 0;
	}
	for (int i = 1; i <= n; i++) {
		tot = 0;
		for (int j = i; j <= n; j++) {
			if (tot >= lst[a[j]] && num[lst[a[j]]] == a[j]) {
				tot = lst[a[j]] - 1;
			}
			num[++tot] = a[j];
			lst[a[j]] = tot;
		}
		for (int j = 1; j <= tot; j++) {
			ans[num[j]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
  return cout << '\n', 0;
}
