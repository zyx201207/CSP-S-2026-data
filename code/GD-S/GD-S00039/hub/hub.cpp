#include <bits/stdc++.h>

using namespace std;

int n, k;
void solve() {
	cin >> n >> k;
	for(int i = 1; i < n; i++) {
		int c;
		cin >> c;
		cin >> c;
	}
	if(n == k)
	cout << "0\n";
	else if(n - k <= 2) cout << "1\n";
	else cout << "1\n";
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while(T--) solve();
	
	return 0;
} 
