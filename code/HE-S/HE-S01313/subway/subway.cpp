#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
int w[500010], k[510];
int a[510][500010], t[510][500010];
vector<pair<int, int>> edge[500010];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; j++)
			scanf("%d%d", &a[i][j], &t[i][j]);
	}
	puts("rp++rp++");
	return 0;
}
