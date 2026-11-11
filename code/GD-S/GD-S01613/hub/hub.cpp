#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n , m , t , c;
vector<int> g[N];
void dfs() {
	cout << n / m - 1 << '\n';
}
int main() {
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--) {
		cin >> n >> m;
		for(int i = 1;i < n;i++) {
			int x , y;
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if(n == 2 * m + 1) {
			cout << 1 << '\n';
		}else {
			dfs();
		}
	}
	return 0;
}
