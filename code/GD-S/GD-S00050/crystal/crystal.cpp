#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, k, sum, cnt, a[N], b[N], d[N];
bool check(int mid, int i) {
	int tmp = b[i] - b[mid - 1];
	return a[i] * (i - mid + 1) - tmp <= m;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int i, j, x, y, z, t;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (i = 1; i <= n; i++)
		b[i] = b[i - 1] + a[i]; 
	int ma = 0;
	for (i = 1; i <= n; i++) {
		int l = 1, r = i, ans = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (check(mid, i))
				r = mid - 1, ans = mid;
			else
				l = mid + 1;
		}
		if (ans != -1)
			ma = max(ma, i - ans + 1);
	}
	cout << ma;
	return 0;
} 
