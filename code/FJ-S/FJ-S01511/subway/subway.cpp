#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int LN_CNT = 505, STN_CNT = 5e5 + 5, SUM_PS_CNT = 5e5 + 5, Q = 1e5 + 5, MAX_PS = 25;
const int ND_CNT = STN_CNT * MAX_PS, EDGE_CNT = (SUM_PS_CNT + STN_CNT * MAX_PS) << 1;

int cid, ln_cnt, stn_cnt, max_ps, q, kt[STN_CNT];
ll ans[Q];
struct Query{
	int src, tgt, id;
	bool operator<(Query &other) {
		return src < other.src;
	}
} qry[Q]; 

int vln[ND_CNT];
int head[ND_CNT], to[EDGE_CNT], nxt[EDGE_CNT], wgt[EDGE_CNT], tot = 1;

int vid(int stn, int ln) {
	return (stn * max_ps) + ln;
}

void add1(int u, int v, int w) {
	wgt[++tot] = w;
	to[tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}

void add(int u, int v, int w) {
	add1(u, v, w);
	add1(v, u, w);
}

bool vis[ND_CNT];
ll dis[ND_CNT];

void dijkstra(int src) {
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll,int>>> q;
	q.push({0, src});
	
	while(!q.empty()) {
		int d = q.top().first, u = q.top().second;
		q.pop();
		
		if (vis[u]) {
			continue;
		}
		
		vis[u] = true;
		dis[u] = d;
		
		for (int i = head[u]; i; i = nxt[i]) {
			int vd = d + wgt[i], v = to[i];
			if (vd < dis[v]) {
				q.push({vd, v});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w" ,stdout);
	
	scanf("%d %d %d %d %d", &cid, &ln_cnt, &stn_cnt, &max_ps, &q);
	for (int i = 1; i <= stn_cnt; ++i) {
		scanf("%d", kt + i);
	}
	
	for (int i = 1; i <= ln_cnt; ++i) {
		int ps_cnt, last_stn = 0, cur_stn, w;
		scanf("%d", &ps_cnt);
		for (int j = 1; j <= ps_cnt; ++j) {
			scanf("%d %d", &cur_stn, &w);
			add(vid(cur_stn, 0), vid(cur_stn, ++vln[cur_stn]), w);
			if (last_stn != 0) {
				add(vid(last_stn, vln[last_stn]), vid(cur_stn, vln[cur_stn]), 0);
			}
			last_stn = cur_stn;
		}
	}
	
	for (int i = 1; i <= q; ++i) {
		scanf("%d %d", &qry[i].src, &qry[i].tgt);
		qry[i].id = i;
	}
	sort(qry + 1, qry + q + 1);
	for (int i = 1; i <= q; ++i) {
		if (qry[i].src != qry[i - 1].src) {
			dijkstra(vid(qry[i].src, 0));
		}
		ans[qry[i].id] = kt[qry[i].src] + dis[vid(qry[i].tgt, 0)] + kt[qry[i].tgt];
	}
	
	for (int i = 1; i <= q; ++i) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}

