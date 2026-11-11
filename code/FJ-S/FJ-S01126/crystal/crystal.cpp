#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

int n, m, a[500005], q[500005];
int B_S(int l, int r, int R) {
	if (l == r) return l;
	int mid = (l + r) / 2;
	if (a[R] * (R - mid + 1) - (q[R] - q[mid - 1]) <= m) return B_S(l, mid, R);
	else return B_S(mid + 1, r, R);
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) q[i] = q[i - 1] + a[i];
	int ans = 1;
	for (int i = n; i >= 1; i--) {
		ans = max(ans, i - B_S(1, i, i) + 1ll);
	}
	cout << ans << endl;
	return 0;
}
