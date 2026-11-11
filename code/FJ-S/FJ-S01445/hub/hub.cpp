#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int c, t, n, k;
void solve();
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while( t-- ) solve();
	return 0; 
}
void solve(){
	cin >> n >> k;
	if (k >= n) cout << 0 << endl;
	else if (k < n && k >= n / 2) cout << 1 << endl;
	else cout << n / 2 - k << endl;
}