#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int c, t;
int n, k;
vector<int> tr[N];
int de[N], vl[N];

void dfs (int x, int fa) {
	de[x] = de[fa] + 1;
	vl[de[x]]++;
	for (int y: tr[x]) {
		if (y != fa) dfs(y, x);
	}
}

int main () {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		int u, v;
		for (int i = 1; i < n; i++) {
			cin >> u >> v;
			tr[u].push_back(v);
			tr[v].push_back(u);
		}
		int ans = n;
		for (int i = 1; i <= n; i++) {
			dfs(i, 0);
			int sm = 0;
			for (int i = 1; i <= n; i++) {
				sm += vl[i];
				if (sm >= k) {
					if (sm == k+1) {
						ans = min(ans, i-1+i-2);
					}
					else {
						ans = min(ans, i-1+i-1);
					}
					break;
				}
			}
			for (int i = 1; i <= n; i++) {
				de[i] = vl[i] = 0;
			}
		}
		cout << ans << '\n';
		for (int i = 1; i <= n; i++) {
			tr[i].clear();
		}
	}
}
