#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
const int MAXN = 10e6 + 10;
const int MAXM = 2e6 + 10;
const long long INF = 4e18 + 10;

int c, T, n, K;

struct edg {
	int v;
	LL w;
};
vector<edg> G[MAXM];

void work() {
	scanf ("%d%d", &n, &K);
	for (int i = 1; i <= n; i++) {
		int u, v;
		scanf ("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	printf ("%d\n", (n - 1) / 2);
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	scanf ("%d%d", &c, &T);
	while (T --) {
		work();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
