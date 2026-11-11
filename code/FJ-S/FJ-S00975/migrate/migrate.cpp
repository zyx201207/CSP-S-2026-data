#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5, M = 2e6 + 5;

int c, t, n, d, x[N], dist[N], cnt[N];
int head[N], nxt[M], ver[M], edge[M], tot = 0;
bool v[N];

void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, nxt[tot] = head[x], head[x] = tot;
}

bool dijkstra(int s, int t) {
	memset(v, 0, sizeof v);
	memset(dist, 0x3f, sizeof dist);
	memset(cnt, 0, sizeof cnt);
	priority_queue<pair<int, int> > q;
	q.push(make_pair(s, 0));
	dist[s] = 0;
	cnt[s] = 1;
	while (q.size()) {
		int x = q.top().first; q.pop();
		if (v[x]) continue;
		v[x] = true;
		for (int i = head[x]; i; i = nxt[i]) {
			int y = ver[i];
			if (dist[y] + edge[i] < dist[x]) {
				dist[x] = dist[y] + edge[i];
				cnt[x] = 1;
				q.push(make_pair(y, -dist[y]));
			} else if (dist[y] + edge[i] == dist[x])
				cnt[x]++;
		}
	}
	return cnt[t] == 2;
}

int main() {
	//freopen("migrate.in", "r", stdin);
	//freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--) {
		memset(head, 0, sizeof head);
		tot = 0;
		scanf("%d%d", &n, &d);
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &x[i]);
		}
		int b = x[2] - x[1];
		for (int i = 1; i <= n; i++) {
			if (b != x[i] - x[i - 1] && i != 1) flag = false;
		}
		if (flag == true) {
			int x1 = d / b;
			int x2 = n - x1 - 2;
			int x3 = x2 / b;
			printf("%d\n", x3);
		}
		else if (n <= 5000) {
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (abs(x[i] - x[j]) <= d)
						add(i, j, abs(x[i] - x[j]));
			int ans = 0;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++) {
					if (dijkstra(i, j))
						ans++;
				}
			printf("%d\n", ans);
		} else printf("0\n");
	}
	return 0;
}
