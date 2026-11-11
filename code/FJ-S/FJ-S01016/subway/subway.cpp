#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll LLLLLL = 1e18;
const int MAXN = 2005, MAXRoute = 505;

struct node {
	ll w;
	vector<int> route;
}a[MAXN];

vector<int> edges[MAXN];
int n, m, d, Ques;
ll t[MAXRoute][MAXN];
ll dist[MAXN][MAXN];
ll tmp[MAXN][MAXRoute];
bool b[MAXRoute][MAXN];

struct point {
	int x, stat;
	ll z;
	bool operator < (const point & A) const {
		return z > A.z;
	}
};
priority_queue<point> q;

void dijkstra(int s) {
	memset(b, false, sizeof(b));
	memset(tmp, 0x3f, sizeof(tmp));
	for (int ro : a[s].route) {
		q.push({s, ro, t[ro][s]});
		tmp[s][ro] = t[ro][s];
	}
	int x, st;
	while (!q.empty()) {
		x = q.top().x, st = q.top().stat;
		q.pop();
		if (b[st][x])
			continue;
		b[st][x] = true;
		for (int y : edges[x]) {
			for (int ds : a[y].route) {
				if (t[ds][x] == -1)
					continue;
				if (st == ds) {
					if (tmp[y][ds] > tmp[x][ds]) {
						tmp[y][ds] = tmp[x][ds];
						q.push({y, ds, tmp[y][ds]});
					}
					continue;
				}
				if (tmp[x][ds] < tmp[x][st] + t[st][x] + t[ds][x])
					continue;
				tmp[x][ds] = tmp[x][st] + t[st][x] + t[ds][x];
				if (tmp[y][ds] > tmp[x][ds]) {
					tmp[y][ds] = tmp[x][ds];
					q.push({y, ds, tmp[y][ds]});
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j : a[i].route) {
			tmp[i][j] += t[j][i];
		}
	}
}

int Testcase;
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(t, 255, sizeof(t));
	scanf("%d%d%d%d%d", &Testcase, &n, &m, &d, &Ques);
	for (int i = 1; i <= m; i++)
		scanf("%lld", &a[i].w);
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		int y = 0, x = 0;
		for (int j = 1; j <= k; j++) {
			scanf("%d", &x);
			scanf("%lld", &t[i][x]);
			if (j > 1) {
				edges[x].push_back(y);
				edges[y].push_back(x);
			}
			a[x].route.push_back(i);
			y = x;
		}
	}
	for (int i = 1; i <= m; i++) {
		dijkstra(i);
		for (int j = 1; j <= m; j++) {
			dist[i][j] = LLLLLL;
			for (int k : a[j].route)
				dist[i][j] = min(dist[i][j], tmp[j][k]);
		}
	}
	
	int u, v;
	for (; Ques--; ) {
		scanf("%d%d", &u, &v);
		printf("%lld\n", dist[u][v] + a[u].w + a[v].w);
	}
	return 0;
}
