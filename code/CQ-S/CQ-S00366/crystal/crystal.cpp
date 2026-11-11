#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int n, m, a[N], g[N], ans;

signed main ()  {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m; ans = 1;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) g[i] = g[i - 1] + a[i];
	for (int i = 2; i <= n; ++i) {
		int l = 0, r = i, mid, res = i;
		while (l < r) {
			mid = (l + r) >> 1;
			if (g[i] - g[mid - 1] + m >= a[i] * (i - mid + 1)) r = mid - 1, res = mid;
			else l = mid + 1;
		}
		if (g[i] - g[res - 1] + m < a[i] * (i - res + 1)) res++;
		if (res != 0 && g[i] - g[res - 2] + m >= a[i] * (i - res + 2)) res--;
		ans = max (ans, i - res + 1);
	}
	cout << ans;
	
	return 0; 
} 
