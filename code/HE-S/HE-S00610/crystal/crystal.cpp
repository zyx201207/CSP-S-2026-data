#include <iostream>
#include <queue>
#include <algorithm>
#define int long long
using namespace std;

const int MXN = 5e5 + 5;
int n, m, l = 1, sum, ans, a[MXN];

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i += 1) cin >> a[i];
	
	sort(a + 1, a + n + 1);
	for (int r = 1; r <= n; r += 1){
		sum += (a[r] - a[r - 1]) * (r - l);
		while (sum > m){
			sum -= a[r] - a[l];
			l += 1;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
} 
