#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, a[N], q[N], ans;

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) q[i] = q[i - 1] + a[i];
	for(int r = 1, l = 1; r <= n; r++){
		while(l < r && (r - l) * a[r] - (q[r - 1] - q[l - 1]) > m) l++;
		ans = max(ans, r - l + 1);
	} 
	cout << ans << "\n";
	return 0;
}
