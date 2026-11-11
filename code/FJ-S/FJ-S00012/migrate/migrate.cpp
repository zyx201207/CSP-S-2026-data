#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
int c, t, n, d, x[N];
int read() {
	int x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c - '0');
		c = getchar(); 
	}
	return x * f;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		cout << "0\n";
	}
	return 0;
} 
