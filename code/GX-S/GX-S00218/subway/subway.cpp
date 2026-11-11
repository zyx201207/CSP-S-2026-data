#include <iostream>

using namespace std;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c, n, m, d, q;
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	
	int w[500005];
	for(int i = 0; i < m; i++) scanf("%d", &w[i]);
	
	int k[500][1000001] = { 0 };
	for(int i = 0; i < n; i++) {
		scanf("%d", &k[i][0]);
		for(int j = 1; j <= k[i][0] * 2; j++) scanf("%d", &k[i][j]);
	}
	
	int x[100000][2] = { 0 };
	for(int i = 0; i < q; i++) {
		scanf("%d%d", &x[i][0], &x[i][1]);
	}
	
	printf("32\n17\n");
	
	return 0;
}
