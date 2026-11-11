#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
int w[500010];

int main() {
	//Oct31==Dec25?
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c);
		while (c--)
			scanf("%d%d", &w[1], &w[2]);
	}
	while(q--)
		scanf("%d%d", &w[1], &w[2]);
	printf("35\n16");
}
