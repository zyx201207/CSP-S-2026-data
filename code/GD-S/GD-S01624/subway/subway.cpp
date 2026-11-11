#include <bits/stdc++.h>
#define PLI pair<long long, int>
using namespace std;
const int N = 505, M = 5e5 + 5;
const long long INFLL = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q;//nœﬂ m’æ 
int w[M], k[N];

vector<PLI> s2r[M], r2s[N];
vector<PLI> g[N];

long long dis[N][N];

void zdl(int s){
	priority_queue<PLI, vector<PLI>, greater<PLI> > pq;
	pq.push({0, s});
	while (!pq.empty()){
		PLI tp = pq.top(); pq.pop();
		int u = tp.second;
		if (dis[s][u] != INFLL) continue;
		dis[s][u] = tp.first;
		for (PLI v : g[u]) {
			pq.push({v.first + dis[s][u], v.second});
		}
	}
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	cout << -1;
	cin >> c >> n >> m >> d >> q;
	for (int i=1; i<=m; i++) {
		cin >> w[i];
	}
	for (int i=1; i<=n; i++) {//500
		cin >> k[i];
		for (int j=1; j<=k[i]; j++) {//kµƒ∫Õ <= 5e5
			int aij, tij;
			cin >> aij >> tij;
			s2r[aij].push_back({tij, i});
			r2s[i].push_back({tij, aij});
		}
	}
//	cout << 0;
//	cout << n <<'\n';
	for (int i=1; i<=n; i++){//
//		cout << i << '\n';
		for (PLI j : r2s[i]) {//5e5
			for (PLI k : s2r[j.second]) {//20
//				cout << i << " " << j.second << " " << k.second << " ";				if (k.second == i) continue;
				g[i].push_back({k.first + j.first, k.second});
				g[k.second].push_back({k.first + j.first, i});
			}
		}
	}
//	cout << 1;
	
	memset(dis, 0x3f, sizeof(dis));
	for (int i=1; i<=n; i++){
		zdl(i);
	}
//	cout << 2;
	
	
	while (q--){
		int x, y;
		long long ans = INFLL;
		cin >> x >> y;
		for (PLI rw1 : s2r[x]){
			for (PLI rw2 : s2r[y]){
				ans = min(ans, 1LL * w[x] + rw1.first + dis[rw1.second][rw2.second] + rw2.first + w[y]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
