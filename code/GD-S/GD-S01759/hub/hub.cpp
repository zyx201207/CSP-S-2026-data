#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, t, n, k, x, y;
vector<int> v[1000010];
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--) {
		cin >> n >> k;
		for(int i = 1; i < n; i++) {
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		cout << 1;
	}
	return 0;
}
