#include <bits/stdc++.h>

#define int long long 

using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], sum[N];
bool check (int x) {
	 for (int i = x; i <= n; i++) {
	 	 int k = sum[i - 1] - sum[i - x];
	 	 if ((x - 1) * a[i] - k <= m) return true;
	 }
	 return false;
}
signed main() {
	
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
    ios :: sync_with_stdio (false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    stable_sort (a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    int l = 1, r = n, mid;
    while (l <= r) {
    	mid = l + r >> 1;
    	if (check (mid)) l = mid + 1;
    	else r = mid - 1;
	}
	cout << l - 1;
	return 0;
} 
