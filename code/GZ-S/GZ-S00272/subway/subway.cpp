//GZ-S00272  贵阳市第三实验中学  闫张玴 
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 505, M = 5e5+10;
int c, m, n, b, p;
int nvt[M]; // Not be avoided time
int sta, en;
int ss[M], ti[M], kk, k; //任一地铁线路中某站站名及时间 
struct st{
	int v, w;
};
vector<st> g[M];
priority_queue<PII, vector<PII>, greater<PII> > q;
int d[M], f[M];

void dijkstra() {
	memset(d, 0x3f, sizeof d);
	memset(f, 0, sizeof f);
	while(!q.empty()) q.pop();
	d[sta] = 0;
	q.push({0, sta});
	while(!q.empty()) {
		int h = q.top().second;
		q.pop();
		if(f[h]) continue;
		f[h] = true;
		for(auto e : g[h]) {
			int to = e.v, w = e.w;
			if(d[h] + w < d[to]) {
				d[to] = d[h] + w;
				q.push({d[to], to});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> b >> p;
	for(int i=1; i<=m; i++) {
		int x;
		cin >> x;
		nvt[i] = x;
	}	
	for(int i=1; i<=n; i++) {
		int x;
		cin >> x;
		for(int j=1; j<=x; j++) {
			cin >> ss[++kk] >> ti[++k];
		}
		for(int j=1; j<=x-1; j++) {
			for(int jj=kk-x+1+j; jj<=kk; jj++) {
				g[ss[jj]].push_back({ss[jj-j], ti[jj] + ti[jj-j]});
				g[ss[jj-j]].push_back({ss[jj], ti[jj] + ti[jj-j]});
			}
		}
	}
	for(int i=1; i<=p; i++) {
		cin >> sta >> en;
		dijkstra();
		cout << d[en] + nvt[sta] + nvt[en] << "\n";
	}
	return 0;
}
