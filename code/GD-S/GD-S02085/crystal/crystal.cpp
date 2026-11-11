#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int MAXN = 5e5 + 5;

template<typename T> void chkMin(T &x, T y) { x = y < x ? y : x; }
template<typename T> void chkMax(T &x, T y) { x = y > x ? y : x; }

int n;
ll m, a[MAXN], pre[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];
	
	int ans = 0;
	for (int r = 1, l = 1; r <= n; ++r) {
		while (l < r && a[r] * (r - l + 1) - pre[r] + pre[l - 1] > m) ++l;
		chkMax(ans, r - l + 1);
	}
	cout << ans;
	
	return 0;
}
