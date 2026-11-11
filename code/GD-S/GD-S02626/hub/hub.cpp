#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e3 + 9;
int c, t, n, k;
vector <int> g[N];

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--){
		cin >> n >> k;
		for (int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if (k == n){
			cout << 0;
			continue;
		}
		int m = (n - 1) / 2;
		int x = m / 2 + 1;
		k--;
		if (k == 0) cout << x << endl;
		else {
			if (m % 2 == 0) k--, x--;
			while (k - 2 >= 0){
				k--, k--, x--;
			}
			if (x <= 0) cout << 1 << endl;
			else cout << x << endl;
		}
	}
	return 0;
}
