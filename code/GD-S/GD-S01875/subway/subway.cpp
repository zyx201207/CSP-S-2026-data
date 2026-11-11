#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 505;
const int MAXM = 500005;
const ll INF_ll = 0x3f3f3f3f3f3f3f3f;

int c;
int n, m, d, q;
ll w[MAXM];
struct way{
	int from;
	ll t;
	way(){}
	way(int _from, int _t):from(_from), t(_t){}
};
vector<way> station[MAXM];
ll G[MAXN][MAXN];
ll ans = 0;

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	memset(G, 0x3f3f3f3f, sizeof(G));
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
		cin >> w[i];
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			ll to, t;
			cin >> to >> t;
			for(auto e : station[to]){
				G[i][e.from] = min(t + e.t, G[i][e.from]);
				G[e.from][i] = min(e.t + t, G[e.from][i]);
			}
			station[to].push_back(way(i, t));
		}
	}

	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j){
					G[i][j] = 0;
					continue;
				}
				if(G[i][k] != INF_ll && G[k][j] != INF_ll)
					G[i][j] = min(G[i][k] + G[k][j], G[i][j]);
			}
		}
	}
/*
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << G[i][j] << " ";
		}
		cout << "\n";
	}
*/
	for(int Q = 1; Q <= q; Q++){
		int x, y;
		cin >> x >> y; 
		ans = INF_ll;
		for(auto i : station[x]){
			for(auto j : station[y]){
				ans = min(G[i.from][j.from] + i.t + j.t + w[x] + w[y], ans);
			}
		}
		cout << ans << endl;
	}
} 
