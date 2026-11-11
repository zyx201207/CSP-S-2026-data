#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 2;

int n, m, ans, a[N];
set <int> s;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i], s.insert(i);
	for (int j = 31;j >= 0;j--) {
		int cnt = 0;
		for (set <int> :: iterator it = s.begin();it != s.end();it++) {
//			cout << "\t" << (*it) << endl;
			cnt += ((a[*it] >> j) & 1);
		}
		if (cnt >= m) {
			vector <int> r;
			for (set <int> :: iterator it = s.begin();it != s.end();it++) {
//				cout << "\t" << (*it) << endl;
				if (!((a[*it] >> j) & 1)) r.push_back(*it);
			}
			for (int i = 0;i < r.size();i++) s.erase(r[i]);
		}
	}
	ans = (1ll << 32) - 1;
	int j = 1;
	for (set <int> :: iterator it = s.begin();it != s.end() && j <= m;it++, j++) {
		ans &= a[*it];
//		cout << a[*it] << " " << ans << endl;
	}
	cout << ans << endl;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
