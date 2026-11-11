#include <bits/stdc++.h>
#define int long long
using namespace std;

int C, T, n, k;

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> C >> T;
	while(T --) {
		cin >> n >> k;
		for(int i = 1;i < n;i ++) {
			int x, y;cin >> x >> y;
		}
		if(n == k) cout << "0\n";
		else cout << "1\n";
	}
	return 0;
}
