#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;
const ll mod = 998244353;
const ll P = 1e9 + 7;
const int N = 5e5 + 5;
int n, m, a[N], pos[N], ans[N];

int main () {
	ios :: sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);

	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	
	stack <int> s;
	for (int i = 1; i <= n; i ++) {
		for (int j = i; j <= n; j ++) {
			if (pos[a[j]] != 0) {
				while (!s.empty () && s.top () != a[j]) {
					pos[s.top ()] = 0;
					s.pop ();
				}
			} else {
				s.push (a[j]);
				pos[a[j]] = s.size ();
			}
		}
		while (!s.empty ()) {
			ans[s.top ()] ++;
			pos[s.top ()] = 0;
			s.pop ();
		}
	}
	for (int i = 1; i <= m; i ++)
		cout << ans[i] << " ";
	return 0;
}
