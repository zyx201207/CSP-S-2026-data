#include <bits/stdc++.h>
#define int long long
using namespace std;
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
int c, T, n, k;
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> c >> T;
	while(T--) {
		cin >> n >> k;
		for(int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
		}
		if(k >= 5) cout << "1\n";
		else cout << k - 1 << '\n';
	}
	return 0;
} 
