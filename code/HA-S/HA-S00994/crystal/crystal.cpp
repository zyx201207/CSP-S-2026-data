#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 5;
int n, m, a[N], pe[N], ans;

signed main ()
{
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	
	ios::sync_with_stdio (false);
	cin.tie (nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) pe[i] = pe[i - 1] + a[i];
	for (int i = 1; i <= n; i++) 
	{
		if (i == 1) ans = max (ans, 1ll);
		else {
			int l = 1, r = i - 1, k = i;
			while (l <= r) 
			{
				int mid = l + r >> 1;
				int val = (i - mid) * a[i] - (pe[i - 1] - pe[mid - 1]);
				if (val <= m) k = mid, r = mid - 1;
				else l = mid + 1;
			}
			ans = max (ans, (i - k + 1));
		}
	}
	
	cout << ans;
	return 0;
}