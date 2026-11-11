#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 205, M = 8e4 + 5;
int C, n, m, d, q, k[N], vis[M];
ll w[M], D[M], a[N][405], t[N][405];
ll DJ(int s, int t){
	memset(D, 0x3f, sizeof(D));
	memset(vis, 0, sizeof(vis));
	D[s] = 0;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
	q.push({0, s});
	while(q.size()){
		int u = q.top().second;
		q.pop();
		if (u == t)
			return D[u];
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = 1;i <= n;i++){
			int id = -1;
			for (int j = 1;j <= k[i];j++){
				if (a[i][j] == u) id = j;
				if (id == -1) continue;
				ll w = t[i][id] + t[i][j];
				if (j != id && D[a[i][j]] > D[u] + w){
					D[a[i][j]] = D[u] + w;
					q.push({D[a[i][j]], a[i][j]});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> C >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) cin >> w[i];
	for (int i = 1;i <= n;i++){
		cin >> k[i];
		for (int j = 1;j <= k[i];j++)
			cin >> a[i][j] >> t[i][j];
	}
	while(q--){
		int s, t;
		cin >> s >> t;
		cout << DJ(s, t) + w[s] + w[t] << endl;
	}
	return 0;
}
