#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
int n;
ll m;
ll a[maxn];
ll d[maxn];
inline void diff() {
	d[1] = 0;
	for (int i = 2; i <= n; i++) {
		d[i] = a[i] - a[i - 1];
	}	
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	diff();
	int l = 1;
	ll now = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		now += d[i] * (i - l);
		while (now > m) {
			now -= a[i] - a[l];
			++l;
		}
//		cerr << l << endl;
		ans = max(ans, i - l + 1);
	}
	cout << ans << endl;
}
