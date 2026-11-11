#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;

int a[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m, ans = -2e9;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++){
			ans = max(ans, (a[i] & a[j]));
		}
	}
	cout << ans << '\n';
	return 0;
}
