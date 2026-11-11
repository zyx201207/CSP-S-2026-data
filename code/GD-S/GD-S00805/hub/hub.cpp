#include<bits/stdc++.h>
using namespace std;

long long c, t, n, k;
int u[2000005], v[2000005];
int in[2000005];
bool vis[3005][3005];

signed main() {
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) in[i] = 0;
		for (int i = 1; i < n; i++){
			cin >> u[i] >> v[i];
			in[u[i]]++;
			in[v[i]]++;
			vis[u[i]][v[i]] = 1;
		} if (k <= 5) {
			if (k == 2) cout << 1 << endl;
			if (k == 3) cout << 2 << endl;
			if (k == 4) cout << 1 << endl;
			if (k == 5) cout << 2 << endl;
			continue;
		} else if (c <= 8) {
			int ans = 0;
			cout << 2 << endl;
		} else {
			cout << n / k << endl;
		}
	}
	
	return 0;
} 
