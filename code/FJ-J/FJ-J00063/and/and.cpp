#include <bits/stdc++.h>
using namespace std;
int v[200050];
bool vis[200050];
int n, m;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v, v + n, greater<int>());
	vis[0] = 1; int res = v[0];
	for (int i = 1; i < m; i++) {
		res &= v[i];
	}
	cout << res;
	return 0;	
}
