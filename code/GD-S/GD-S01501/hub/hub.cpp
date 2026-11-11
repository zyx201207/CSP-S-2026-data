#include <bits/stdc++.h>
using namespace std;
vector<int> G[1000005];
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	scanf("%d %d", &c, &t);
	while(t--) {
		for (auto i : G) {
			i.resize(0);
		}
		int n, k;
		scanf("%d %d", &n, &k);
		for (int i = 1; i < n; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
	}
	while(true){
		;
	}
}
