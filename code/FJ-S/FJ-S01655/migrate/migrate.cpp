#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 2e6 + 10;
int c, t, n, d;
int a[N];

inline int solve() {
	int ans = 0;
	int b = d / (a[2] - a[1]);
	
	if(b >= 2)
	for(int i = 1; i + (b + b - 1) <= n; ++i) ans ++;
		
	
	return ans;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		cout << solve() << "\n";
	
	}
	return 0;
}
