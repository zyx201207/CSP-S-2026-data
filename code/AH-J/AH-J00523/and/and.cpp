#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
int a[MAXN], n, m, cnt[30], t = 0;
vector <int> v;
int main () {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	ios::sync_with_stdio (false), cin.tie (0), cout.tie (0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	for (int k = 29; k >= 0; -- k) {
		for (int i = 1; i <= n; ++ i) {
			if (a[i] & (1 << k)) cnt[k] ++;
		}
	}
	for (int k = 29; k >= 0; -- k) if (cnt[k] >= m) { t = k; break; }
	for (int i = 1; i <= n; ++ i) if (a[i] & (1 << t)) v.push_back (a[i]);
	int dc = 0;
	for (int k = t; k >= 0; -- k) {
		int len = v.size ();
		if (len == m) break;
		int cnt = 0;
		for (int u : v) if (u & (1 << k)) cnt ++;
		if (cnt - dc >= m) for (int i = 0; i < (int) v.size (); ++ i) if (!(v[i] & (1 << k))) v[i] = -1, dc ++, i --;
	}
	int ans = v[0];
	for (int i = 1; i < (int) v.size (); ++ i) ans &= v[i];
	cout << ans;
	return 0;
}
