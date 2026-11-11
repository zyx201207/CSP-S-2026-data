#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 5, MAXR = 5e2 + 5;
int w[MAXN], rail[MAXN][22], tme[MAXN][22], cnt[MAXN];
ll dis[MAXR][MAXR];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int s, t;
			cin >> s >> t;
			rail[s][++cnt[s]] = i;
			tme[s][cnt[s]] = t;
		}
	}
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dis[i][j] = ((i == j) ? 0 : 4e18);
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= cnt[i]; j++)
			for(int k = j + 1; k <= cnt[i]; k++){
				int u = rail[i][j], v = rail[i][k];
				dis[u][v] = min(dis[u][v], (ll)tme[i][j] + tme[i][k]);
				dis[v][u] = min(dis[v][u], (ll)tme[i][j] + tme[i][k]);
			}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++){
				if(dis[i][k] == 4e18 || dis[k][j] == 4e18) continue;
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
	while(q--){
		int u, v;
		cin >> u >> v;
		ll ans = 4e18;
		for(int i = 1; i <= cnt[u]; i++)
			for(int j = 1; j <= cnt[v]; j++){
				if(dis[rail[u][i]][rail[v][j]] == 4e18) continue;
				ll cur = tme[u][i] + dis[rail[u][i]][rail[v][j]] + tme[v][j];
				ans = min(ans, cur);
			}
		cout << ans + w[u] + w[v] << "\n";
	}
	return 0;
}
