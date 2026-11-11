#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

#define int long long

using namespace std;
typedef pair<int, int> pii;

const int M = 1009;
const int MAX = (int)1e17 + 9;

int a, b, c;
int ans = 0;

int asezzhbsy;

int qqq;

int dis[M][M];

struct AC {
   int to;
   int w;
   int nxt;
};

AC nb[M << 2];

int head[M];
int E = 0;

int qz[M];

void init() {
	E = 0;
	memset(head, -1, sizeof head);
}

void add(int qq, int ww, int ee) {
	nb[E].to = ww;
	nb[E].w = ee;
	nb[E].nxt = head[qq];
	head[qq] = E;
	E++;
}

priority_queue<pii, vector<pii>, greater<pii>>q;

void dijkstra(int qd) {
	for (int i = 0; i <= a + b; ++i) {
		qz[i] = MAX;
	}
	qz[qd] = 0;
	q.push({0, qd});
	while (!q.empty()) {
		pii ni;
		ni = q.top();
		q.pop();
		if (qz[ni.second] < ni.first) {
			continue;
		}
		for (int i = head[ni.second]; ~i; i = nb[i].nxt) {
			if (qz[ni.second] + nb[i].w < qz[nb[i].to]) {
				qz[nb[i].to] = qz[ni.second] + nb[i].w;
				q.push({qz[nb[i].to], nb[i].to});
			}
		}
	}
	for (int i = 0; i <= a + b; ++i) {
		dis[qd][i] = qz[i];
	}
}

int zhb[M][M], zhh[M][M];

int w[M];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
    init();
	scanf("%lld%lld%lld%lld%lld", &asezzhbsy, &a, &b, &c, &qqq);
	for (int i = 1; i <= b; ++i) {
		scanf("%lld", &w[i]);
		add(0, i, w[i]);
		add(i, 0, w[i]);
	}
	for (int i = 1, k; i <= a; ++i) {
		scanf("%lld", &k);
		for (int j = 1; j <= k; ++j) {
			scanf("%lld%lld", &zhb[i][j], &zhh[i][j]);
			if (j == 1) {
				add(0, i + b, zhh[i][j]);
				add(i + b, zhb[i][j], 0);
			} else {
				add(zhb[i][j - 1], zhb[i][j], zhh[i][j]);
			}
		}
	}
	for (int i = 0; i <= b + a; ++i) {
		dijkstra(i);
	}
	int x, y;
	while (qqq--) {
		scanf("%lld%lld", &x, &y);
		printf("%lld\n", w[x] + dis[0][y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//贵州省 安顺市第二高级中学 郑焕博 GZ-S00151
