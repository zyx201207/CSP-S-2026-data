#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
const int N = 1000005;
using namespace std;

int c, T;
int n, k;
vector<int> d[N];
int dep[N];

void dfs(int x, int fa) {
	dep[x] = dep[fa] + 1;
	for (int i = 0; i < d[x].size(); i++)
		if (d[x][i] != fa)
			dfs(d[x][i], x);
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		cin >> n >> k;
//		for (int i = 1; i <= n; i++)
//			d[i].clear();
//		for (int i = 1, u, v; i < n; i++) {
//			cin >> u >> v;
//			d[u].push_back(v);
//			d[v].push_back(u);
//		}
//		dfs(1, 0);
//		int maxdep = 0, maxid;
//		for (int i = 1; i <= n; i++)
//			if (dep[i] > maxdep)
//				maxdep = dep[i], maxid = i;
//		dfs(maxid, 0);
//		maxdep = 0;
//		for (int i = 1; i <= n; i++)
//			if (dep[i] > maxdep)
//				maxdep = dep[i], maxid = i;
		cout << (n / 2 - k + 3) / 4 + 1 << endl;
	}
	return 0;
}
