#include <bits/stdc++.h>
#define itn int
#define int long long
#define FOR(i,l,r) for(int i = l;i <= r;i++)
using namespace std;

const int INF = 1e18;

struct Edge {
	int bel;
	int u,v;
	int wu,wv;
	int nex;
}G[2005];
int cnt;

struct line {
	int id;
	int wei;
	int nod;
	int num;
	bool operator>(const line &oth)const {
		return wei > oth.wei;
	}
};

priority_queue <line,vector<line>,greater<line> > q;

int head[500005];

int dis[500005];

int Val[500005];
int vis[500005];

int Number;
int n,m,d,Q; // n Îª±ß!, m Îªµã! 
int ans;

void addEdge(int id, int u,int v,int uw,int vw) {
	cnt++;
	G[cnt].bel = id;
	G[cnt].u = u;
	G[cnt].v = v;
	G[cnt].wu = uw;
	G[cnt].wv = vw;
	G[cnt].nex = head[u];
	head[u] = cnt;
}

void Dijkstra(int s) {
	FOR(i, 1, m) vis[i] = 0;
	FOR(i, 1, m) dis[i] = INF;
	dis[s] = 0;
	q.push({0,0,s,0});
	while(!q.empty()) {
		line t = q.top();
		q.pop();
		if (vis[t.nod]) continue;
		vis[t.nod] = 1;
//		cout << t.id << ' ' << t.nod << ' ' << t.num << ' ' << t.wei << '\n';
		for(int i = head[t.nod];i;i = G[i].nex) {
//			cout << i << '\n';
			int cost = t.wei + G[i].wu + G[i].wv;
			if (t.num == G[i].bel) cost = cost - G[t.id].wv - G[i].wu;
			if (cost < dis[G[i].v]) {
				dis[G[i].v] = cost;
				if (!vis[G[i].v])
					q.push({i,cost, G[i].v, G[i].bel});
			}
		}
	}
}

void SolveNormal() {
	FOR(i, 1, n) {
		int t;
//		t = read();
		cin >> t;
//		cout << t << '\n';
		int lu = -1 , luw = -1;
		int nu, nuw;
		while(t--) {
//			nu = read();
//			nuw = read();
			cin >> nu >> nuw;
//			cout << nu << ' ' << nuw << '\n';
			if (lu != -1 && luw != -1) {
				addEdge(i, lu, nu, luw, nuw);
				addEdge(i, nu, lu, nuw, luw);
			}
			lu = nu;
			luw = nuw;
		}
	}
	int lastx = 0;
	while(Q--) {
		int x,y;
		cin >> x >> y;
//		x = read();
//		y = read();
		if (x != lastx) Dijkstra(x);
		lastx = x;
		cout << dis[y] + Val[x] + Val[y] << '\n';
	}
}

#undef int
int main () {
#define int long long

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> Number >> n >> m >> d >> Q;
//	Number = read();
//	n = read();
//	m = read();
//	d = read();
//	Q = read();
	
//	FOR(i, 1, m) Val[i] = read();
	FOR(i, 1, m) cin >> Val[i];
	
	G[0].bel = G[0].nex = G[0].u = G[0].v = G[0].wu = G[0].wv = 0;
	
	SolveNormal();
	
//	FOR(i, 1, 8) cout << G[i].bel << ' ' << G[i].nex << '\n' << G[i].u << "->" << G[i].v << '\n' << G[i].wu << ' ' << G[i].wv << "\n\n";
	
	return 0;
}
