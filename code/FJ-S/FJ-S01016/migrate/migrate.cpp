#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 5005;

vector<int> g[MAXN];
int CCC, TTT;
int n, noe[MAXN], cnt[MAXN];
ll d, X[MAXN];
int front, rear, q[MAXN + MAXN];

void BFS(int s) {
	memset(noe, 0x3f, sizeof(noe));
	memset(cnt, 0, sizeof(cnt));
	front = 1, rear = 0;
	q[++rear] = s;
	noe[s] = 0;
	while (front <= rear) {
		int x = q[front++];
		for (int y : g[x]) {
			if (noe[y] == 0x3f3f3f3f || noe[y] == noe[x] + 1) {
				noe[y] = noe[x] + 1;
				++cnt[y];
				q[++rear] = y;
			}
		}
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &CCC, &TTT);
	while (TTT--) {
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &X[i]);
			g[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (abs(X[i] - X[j]) <= d)
					g[i].push_back(j);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			BFS(i);
			for (int j = 1; j <= n; j++) {
				if (cnt[j] == 2)
					++ans;
			}
		}
		printf("%d\n", ans / 2);
	}
	return 0;
}
