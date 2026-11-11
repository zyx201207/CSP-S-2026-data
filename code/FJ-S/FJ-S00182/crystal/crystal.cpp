//long long สýื้ 
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 500010;
int n;
LL m, a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int r = 0, ans = 0;
	LL sum = 0;
	for (int l = 1; l <= n; l++) {
		if (r < l) r = l, sum = 0;
		while (r < n && sum + (a[r + 1] - a[r]) * (r - l + 1) <= m)
			sum += 1ll * (a[r + 1] - a[r]) * (r - l + 1),
			r++;
		ans = max(ans, r - l + 1);
		sum -= a[r] - a[l];
	}
	cout << ans << "\n";
	return 0;
}
