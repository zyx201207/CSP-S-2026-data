#include <bits/stdc++.h>
#define int long long
#define N 500005
#define rep(x, y, z) for (int x = y; x <= z; x++)
#define rrep(x, y, z) for (int x = y; x >= z; x--)
#define inf 1e18
using namespace std;
int n, m, a[N], vis[N], last[N], ans[N];
stack<int> s;
#undef int
int main() {
#define int long long
	freopen("card.in", "r", stdin), freopen("card.out", "w", stdout);
	cin >> n >> m;
	int flg = 1;
	rep (i, 1, n) cin >> a[i], last[a[i]] = i;
	rep (i, 2, n) if (a[i] < a[i - 1]) {
		flg = 0;
		break;
	}
	if (m == 1) cout << n, exit(0);
	if (flg) rep (i, 1, m) cout << last[i] << ' ';
	else {
		rep (T, 1, n) {
			while (!s.empty()) s.pop();
			rep (i, T, n) {
				if (vis[a[i]]) {
					while (a[s.top()] != a[i]) vis[a[s.top()]] = 0, s.pop();
				} else vis[a[i]] = 1, s.push(i);
			}
			rep (i, 1, m) ans[i] += vis[i], vis[i] = 0;
		}
		rep (i, 1, m) cout << ans[i] << ' ';
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
