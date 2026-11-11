#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;

bool ok[N];
int n, m, a[N], ans;

signed main ()
{
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	
	
	ios::sync_with_stdio (false);
	cin.tie (nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i], ok[i] = true; 
	
	for (int k = 30; k >= 0; k--) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) if (((a[i] >> k) & 1) && ok[i]) cnt++; 
		if (cnt >= m) {
			ans = ans + (1 << k);
			for (int i = 1; i <= n; i++) if ((!((a[i] >> k) & 1)) && ok[i]) ok[i] = false;
		} 
	}	
	
	cout << ans;
	
	return 0;
}
/*
5 3
31 3 1 15 7
*/
