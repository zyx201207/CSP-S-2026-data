#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define pii pair<int, int>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pll pair<long long, long long>
#define debug(x) cerr << #x << ": " << (x) << "\n"
#define ll long long
#define ull unsigned long long
#define uint unsigned int
using namespace std;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n, m, d, q;
int ids[500007], idr[507], tot; // 站台、线路在图中的标号
int k[507];
vector<int> a[507];
vector<ll> t[507];
ll w[500007];
vector<pil> g[500607];
vector<vector<ll>> dist;
void dij(int st){
	dist[st][st] = 0;
	priority_queue<pli, vector<pli>, greater<pli>> q;
	q.push({0, st});
	while(q.size()){
		int u = q.top().se;
		ll d = q.top().fi;
		q.pop();
		if(d != dist[st][u]) continue;
		for(auto it : g[u]){
			int v = it.fi;
			ll c = it.se;
			if(dist[st][v] > dist[st][u] + c){
				dist[st][v] = dist[st][u] + c;
				q.push({dist[st][v], v});
			}
		}
	}
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int CCC;
	cin >> CCC;
	cin >> n >> m >> d >> q;
	for(int i = 1; i <= n; i++) idr[i] = ++tot;
	for(int i = 1; i <= m; i++) ids[i] = ++tot;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		a[i].resize(k[i] + 2);
		t[i].resize(k[i] + 2);
		for(int j = 1; j <= k[i]; j++){
			cin >> a[i][j] >> t[i][j];
			g[ids[a[i][j]]].pb({idr[i], t[i][j]});
			g[idr[i]].pb({ids[a[i][j]], t[i][j]});
		}
	}
	dist = vector<vector<ll>>(n + 2, vector<ll>(n + m + 2, inf));
	for(int i = 1; i <= n; i++) dij(idr[i]);
	while(q--){
		int x, y;
		cin >> x >> y;
		ll ans = inf;
		for(int i = 1; i <= n; i++)
			ans = min(ans, dist[idr[i]][ids[x]] + dist[idr[i]][ids[y]]);
		ans += w[x] + w[y];
		cout << ans << "\n";
	}
}

