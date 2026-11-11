#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
const int M = 5e5 + 5;
const int N = 505;
struct Subway {
	int k;
	vector<pii> st;
} sub[N];
int c, n, m, d, q, w[M];
ll Dist[N][N];
void Init() {
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= m; j++)
			Dist[i][j] = LLONG_MAX;
	for(int i = 1; i <= m; i++)
		Dist[i][i] = 0;
	for(int i = 1; i <= m; i++)
		cin >> w[i];
}
void Build() {
	for(int i = 1; i <= n; i++) {
		cin >> sub[i].k;
		for(int j = 1; j <= sub[i].k; j++) {
			int a, t;
			cin >> a >> t;
			sub[i].st.push_back({a, t});
			for(int k = 0; k < j - 1; k++) {
				ll p = sub[i].st[k].first;
				ll q = sub[i].st[k].second;
				Dist[p][a] = min(q + t, Dist[p][a]);
				Dist[a][p] = Dist[p][a];
			}
		}
	}
}
void Floyd() {
	for(int k = 1; k <= m; k++) {
		for(int i = 1; i <= m; i++) {
			if(k == i) continue;
			for(int j = 1; j <= m; j++) {
				if(k == j || i <= j) continue;
				if(Dist[i][k] == LLONG_MAX)
					continue;
				if(Dist[j][k] == LLONG_MAX)
					continue;
				Dist[j][i] = Dist[i][j] = min(Dist[i][k] + Dist[k][j], Dist[i][j]);
			}
		}
	}
}
void Query() {
	while(q--) {
		int x, y;
		cin >> x >> y;
		cout << Dist[x][y] + w[x] + w[y] << '\n';
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	Init();
	Build();
	Floyd();
	Query();
	return 0;
}