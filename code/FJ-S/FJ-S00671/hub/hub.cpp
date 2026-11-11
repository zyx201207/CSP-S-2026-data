#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
vector<int> g[N];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	scanf("%d%d", &c, &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 1;i < n;i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		printf("%d\n", max(n / c + c, 1));
	}
	return 0;
}
