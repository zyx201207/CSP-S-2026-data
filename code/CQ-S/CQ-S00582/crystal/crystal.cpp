#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MAXN = 5e5 + 5;

int n, m, ls[MAXN], sum[MAXN];
 

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> ls[i];
	sort(ls + 1, ls + 1 + n);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + ls[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i - 1, pos = i;
		while (l <= r) {
			int mid = l + r >> 1;
			if (ls[i] * (i - mid) - (sum[i - 1] - sum[mid - 1]) <= m) pos = mid, r = mid - 1;
			else l = mid + 1; 
		}
		ans = max(ans, i - pos + 1);
	}
	cout << ans;
	return 0;
}
