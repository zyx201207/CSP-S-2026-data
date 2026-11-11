#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

const int N = 510, M = 5e5 + 10;
const ll inf = 1e18; 
int c, n, m, k, d, q, w[M], a, t, x, y;
ll f[N][N];
vector<pair<int, int> > g[M];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k;
		while(k--){
			cin >> a >> t;
			g[a].push_back({i, t});
		}
		for(int j = 1; j <= n; j++) f[i][j] = inf;
		f[i][i] = 0;
	}
	for(int i = 1; i <= m; i++){
		for(auto p1: g[i]){
			for(auto p2: g[i]){
				f[p1.first][p2.first] = min(f[p1.first][p2.first], (ll)p1.second+p2.second);
				f[p2.first][p1.first] = min(f[p2.first][p1.first], (ll)p1.second+p2.second);
			}
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
		}
	}
	while(q--){
		cin >> x >> y;
		ll ans = inf;
		for(auto i: g[x]){
			for(auto j: g[y]){
				ans = min(ans, i.second + j.second + f[i.first][j.first]);
			}
		}
		cout << ans+w[x]+w[y] << '\n';
	}
	return 0;
}
