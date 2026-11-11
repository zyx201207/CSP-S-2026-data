#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

#define int long long

using namespace std;
typedef pair<int, int> pii;

const int M = 1000009;
const int MAX = (int)1e17 + 9;

int ji[M];

int a, b, c, d;
int ans = 0;

int sy, T;

struct AC {
   int to;
   int w;
   int nxt;
};


AC nb[M << 1];

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
int cnt[M];

int dijkstra(int qd, int zd) {
	for (int i = 1; i <= a; ++i) {
		qz[i] = MAX;
		cnt[i] = 0;
	}
	qz[qd] = 0;
	cnt[qd] = 1LL;
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
			if (qz[ni.second] + nb[i].w == qz[nb[i].to]) {
			    cnt[nb[i].to] += cnt[ni.second];
			}
		}
	}
	if (qz[zd] == MAX) {
		return 0;
	}
	return cnt[zd];
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &sy, &T);
	while (T--) {
		init();
		scanf("%lld%lld", &a, &d);
		for (int i = 1; i <= a; ++i) {
			scanf("%lld", &ji[i]);
		}
		for (int i = 1; i < a; ++i) {
			for (int j = i + 1; j <= a; ++j) {
				if (abs(ji[j] - ji[i]) <= d) {
					add(i, j, 1LL);
				}
			}
		}
		int ans = 0;
		for (int i = 1; i < a; ++i) {
			for (int j = i + 1; j <= a; ++j) {
				if (dijkstra(i, j) == 2LL) {
					++ans;
				}
			}
		}
		printf("%lld\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//贵州省 安顺市第二高级中学 郑焕博 GZ-S00151
