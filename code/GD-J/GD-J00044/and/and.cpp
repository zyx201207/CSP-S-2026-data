#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, k, sum, cnt, a[N], vis[N];
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
	int i, j, x, y, z, t;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0, a1 = (1 << 30); i <= 30; i++, a1 >>= 1) {
		sum = 0;
		for (j = 1; j <= n; j++)
			if (!vis[j] && (a[j] & a1))
				sum++;
		if (sum >= m) {
			for (j = 1; j <= n; j++)
				if (!(a[j] & a1))
					vis[j] = 1; 
		}
	}
	int ans = -1;
	for (i = 1; i <= n; i++)
		if (!vis[i] && cnt < m) {
			if (ans == -1)
				ans = a[i];
			else
				ans = ans & a[i];
			cnt++;
		}
	cout << ans;
	return 0;
}
