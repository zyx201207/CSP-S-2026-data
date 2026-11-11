#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000010];
void solve() {
	int n, d;
	cin >> n >> d;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	if(n == 1) {
		cout << 0 << '\n';
		return;
	}
	int x = a[2] - a[1]; 
	d = d / x;
	if(d <= 1) {
		cout << 0 << '\n';
		return;
	}
	cout << n - d + 1 << '\n';
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout); 
	int c, T;
	cin >> c >> T;
	while(T --) {
		solve();
	} 
	return 0;
}
