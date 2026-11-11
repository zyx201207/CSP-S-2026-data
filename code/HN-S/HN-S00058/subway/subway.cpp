#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 5; 
int c, n, m, d, q;
int w[N];
int dis[N][N];
vector<pair<int, int> > e[N];
struct node {
	int v, w;
};
bool operator < (const node u, const node v) {
	return u.w < v.w;
}
priority_queue<node> pq;
void dij(int st) {
	dis[st][st] = 0;
	pq.push({st, 0});
	while(!pq.empty()) {
		node p = pq.top();
		pq.pop();
		int u = p.v;
		int w1 = p.w;
		for(auto i : e[u]) {
			int v = i.first;
			int w2 = i.second;
			if(w1 + w2 < dis[st][v]) {
				dis[st][v] = w1 + w2;
				pq.push({v, dis[st][v]});
			}
		}
	}
}
int read() {
	int res = 0;
	char ch;
	ch = getchar();
	while(ch < '0' || ch > '9')
		ch = getchar();
	res = ch - '0';
	ch = getchar();
	while('0' <= ch && ch <= '9') {
		res = res * 10 + ch - '0';
		ch = getchar();
	}
		
	return res;
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read();
	m = read();
	n = read();
	d = read();
	q = read();
	for(int i = 1; i <= n; i++)
		w[i] = read();
	for(int i = 1; i <= m; i++) {
		int k;
		k = read();
		while(k--) {
			int u, w;
			u = read();
			w = read();
			e[u].push_back({n + i, w});
			e[n + i].push_back({u, w});			
		}
	}
	memset(dis, 60, sizeof(dis));
	for(int i = 1; i <= n; i++)
		dij(i);
	while(q--) {
		int x, y;
		x = read();
		y = read();
		printf("%lld\n", dis[x][y] + w[x] + w[y]);
	}
	return 0;
}
