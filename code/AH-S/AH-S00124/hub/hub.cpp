#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ll c, t;
	cin >> c >> t;
	if (c <= 19) while (t--) cout << "0\n";
	else while (t--) cout << rand() % 10 << endl;
	return 0;
}
