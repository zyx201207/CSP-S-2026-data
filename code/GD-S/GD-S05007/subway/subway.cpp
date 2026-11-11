#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll MAXN = 2e3+5;
const ll INF = 1e18;

ll c, n, m, d, q, tot, w[MAXN];
ll G[MAXN][MAXN];

void init(){
	for(ll i = 0; i <= MAXN-5; i++){
		G[i][i] = 0;
		for(ll j = 0; j <= MAXN-5; j++){
			if(i == j) continue;
			G[i][j] = INF;
		}
	}
	return;
}

int main(){
//	freopen("subway3.in", "r", stdin);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for(ll i = 1; i <= m; i++){
		cin >> w[i];
	}
	init();
	tot = m; 
	vector<ll> tmp;
	// 1~mÎªÕ¾Ìü 
	for(ll i = 1; i <= n; i++){
		ll k, a, t;cin >> k;
		tmp.clear();
		while(k--){
			cin >> a >> t;
			tot++;
//			G[a][tot] = w[a];
			G[tot][a] = t;
			G[a][tot] = t;
			for(auto u: tmp){
				G[u][tot] = 0;
				G[tot][u] = 0;
			}tmp.push_back(tot);
		}
	}
	for(ll k = 1; k <= tot; k++){
		for(ll i = 1; i <= tot; i++){
			for(ll j = 1; j <= tot; j++){
				if(i == j || j == k || i == k || G[i][k] == INF || G[k][j] == INF) continue;
				G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
			}
		}
	}
	while(q--){
		ll x, y;cin >> x >> y;
		cout << G[x][y]+w[x]+w[y] << endl;
	}
	return 0;
} 
