#include <stdio.h>
#include <vector>
using std :: vector;
#define FileIO(str) freopen(str".in", "r", stdin); freopen(str".out", "w", stdout);
int c, t, n, an, cnt, ccnt;
long long d, x[2000001];
vector<long long> edg[2000001], edd;
void dfs(int x, int g, int cur) {
	edd.emplace_back(x);
	if (x == g) {
		if (an > cur) {
			an = cur;
			cnt = 1;
		}
		else if (an == cur) {
			++cnt;
		}
		return;
	}
	for (int i : edg[x]) {
//		printf("%d->%d\n", i, x);
		dfs(i, g, cur + 1);
		edd.pop_back();
//		printf("return\n");
	}
}
int main() {
//	freopen("migrate1.in", "r", stdin);
	FileIO("migrate");
	scanf("%d%d", &c, &t);
	while (t--) {
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; ++i) {
			edg[i].clear();
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &x[i]);
			for (int j = i - 1; j >= 1; --j) {
				if (x[i] - x[j] > d) {
					break;
				}
				edg[j].emplace_back(i);
			}
		}
		ccnt = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				an = 2147483647;
				cnt = 0;
				dfs(i, j, 0);
				edd.clear();
				if (cnt == 2) {
					++ccnt;
				}
			}
		}
		printf("%d\n", ccnt);
	}
}
