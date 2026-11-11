#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 5e5 + 10, INF = 0x3f3f3f3f;

int n;
LL m, a[N], s[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i, res = INF;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (s[r] * (r - mid) - (s[r - 1] - s[mid - 1]) <= m)
				res = mid, r = mid - 1;
			else
				l = mid + 1;
		} 
		ans = max(ans, i - res + 1);
//		cout << "****" << res << '\n';
	}
	cout << ans << '\n';
	return 0;
}
