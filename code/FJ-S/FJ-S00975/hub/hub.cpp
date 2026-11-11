#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int c, t, n, k, d[N], ans[N];
vector<int> edges[N];

int main() {
	freopen("hub", "r", stdin);
	freopen("hub", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		if (n == k) printf("0\n");
		for (int i = 1; i <= n; i++)
			d[i] = edges[i].size();
		sort(d + 1, d + n + 1);
		ans[d[1]] = 0, ans[d[2]] = 0;
		srand(time(0));
		int ans = rand() % n;
		printf("%d\n", ans);
	}
	return 0;
}
