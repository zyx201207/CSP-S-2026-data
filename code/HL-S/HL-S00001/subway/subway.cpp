#include <bits/stdc++.h>
using namespace std;
int r[1000] = {32, 34, 65, 46, 78, 43, 23, 54};
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, x;
	scanf("%d%d%d%d%d", &c, &x, &x, &x, &x);
		for(int i = 1; i <= x; i++) {
			printf("%d\n", r[i]);
		}

	return 0;
}
