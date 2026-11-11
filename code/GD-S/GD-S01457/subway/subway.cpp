#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 5e5 + 10;
vector<int> Ga[510], Gb[N];
int K[510];
LL bL[510][510], dis[510][510];
unordered_map<int, LL> mp[510];
bool v[510];
int TC, n, m, D, q;

struct node {
	int x; LL d;
};
bool operator<(node na, node nb) {
	na.d > nb.d;
}

priority_queue<node> Q;

void dijkstra(int st) {
	memset(v, 0, sizeof(v));
	Q.push((node){st, 0}); dis[st][st] = 0;
	while (!Q.empty()) {
		node no = Q.top(); Q.pop();
		if (v[no.x]) continue;
		v[no.x] = 1;
		for (int y = 1; y <= n; y ++) if (bL[no.x][y] != bL[0][0]) {
			if (dis[st][y] > dis[st][no.x] + bL[no.x][y]) {
				dis[st][y] = dis[st][no.x] + bL[no.x][y];
				Q.push((node){y, dis[st][y]});
			}
		}
	}
}

LL W[N];

int main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> TC >> n >> m >> D >> q;
	for (int i = 1; i <= m; i ++) {
		cin >> W[i]; 
	}
	for (int i = 1; i <= n; i ++) {
		cin >> K[i];
		for (int j = 0; j < K[i]; j ++) {
			int x; LL t;
			cin >> x >> t;
			mp[i][x] = t;
			Ga[i].push_back(x);
			Gb[x].push_back(i);
		}
	}
	
	memset(bL, 0x7f, sizeof(bL));
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < K[i]; j ++) {
			int x = Ga[i][j];
			for (int z : Gb[x]) {
				bL[i][z] = min(bL[i][z], mp[i][x] + mp[z][x]);
				bL[z][i] = bL[i][z];
			}
		}
	}
	
	memset(dis, 0x7f, sizeof(dis));
	for (int i = 1; i <= n; i ++) {
		dijkstra(i);
	}
	
	while (q --) {
		int x, y;
		cin >> x >> y;
		LL ans = W[x] + W[y];
		LL sum = 2e18;
		for (int i : Gb[x]) {
			LL tmp = mp[i][x];
			for (int j : Gb[y]) {
				LL ned = mp[j][y] + dis[i][j];
				sum = min(sum, tmp + ned);
			}
		}
		cout << ans + sum << "\n";
	}
	
	return 0;
}
