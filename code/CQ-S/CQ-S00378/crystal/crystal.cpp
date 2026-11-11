#include <bits/stdc++.h>
#define int long long 
const int N = 5e5 + 5; 
using namespace std; 
int n, m, ans; 
int a[N], b[N]; 
inline void solve() {
	cin >> n >> m; 
	for(int i = 1; i <= n; ++i) cin >> a[i]; 
	sort(a + 1, a + n + 1); 
	for(int i = 1; i < n; ++i) b[i] = a[i + 1] - a[i], a[i] = b[i], b[i] = b[i - 1] + a[i]; 
	int L = 1, R = 1, sum = 0; 
	while(R < n) {
		sum += (R - L + 1) * a[R]; 
		++R; 
		while(sum > m) {
			sum -= (b[R] - b[L - 1]); 
			++L; 
		}
		ans = max(ans, R - L + 1); 
	}
	cout << ans << "\n"; 
	return ; 
}
signed main() {
	freopen("crystal.in", "r", stdin); 
	freopen("crystal.out", "w", stdout); 
	ios::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0); 
	solve(); 
	return 0; 
}
