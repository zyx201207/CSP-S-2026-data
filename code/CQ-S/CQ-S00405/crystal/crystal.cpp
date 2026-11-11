/*
luogu uid:1020627
miaomiaomiao 
*/
#include <bits/stdc++.h>
using ll = long long;
const int N = 500000 + 10;
ll a[N], sum[N];
int n; ll m;

ll get(int l, int r) { return sum[r] - sum[l - 1]; }

int main() {
	freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
	std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) std::cin >> a[i];
	std::sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i - 1, pos = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[i] * (i - mid) - get(mid, i - 1) <= m) pos = mid, r = mid - 1;
			else l = mid + 1;
		}
		if (pos == -1) continue;
		ans = std::max(ans, i - pos + 1);
	}
	std::cout << ans << '\n';
	return 0;
}
// 我开智了??
// 2min 想出思路
// 14.38 过掉大样例????? 

