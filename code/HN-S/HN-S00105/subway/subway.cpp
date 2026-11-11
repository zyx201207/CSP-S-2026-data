#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MAXN = 505;
int n, m, d, q;
ll w[MAXN];
vector<ll> a[MAXN], t[MAXN];
//vector<array<int, 2>> g[MAXN];
map<ll, vector<array<ll, 2> > > mp;
map<ll, ll> co[MAXN];
ll g[MAXN][MAXN];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		vector<ll> tt(k + 1, 0);
		vector<ll> ta(k + 1, 0);
		for(int j = 1; j <= k; j++){
			cin >> ta[j] >> tt[j];
			mp[ta[j]].push_back({i, tt[j]});
//			if(mp.count(0)){
//				cerr<<i<<endl;
//				return 0;
//			}
			co[i][ta[j]] = tt[j];
		}
	}
	memset(g, 0x3f, sizeof(g));
	for(int i = 1; i <= n; i++) g[i][i] = 0;
	for(auto x : mp){
		int v = x.first;
		auto k = x.second;
		for(auto y : k){
			for(auto z : k){
				if(y == z) continue;
				g[y[0]][z[0]] = min(g[y[0]][z[0]], y[1] + z[1]);
			}
//			cerr << y[0] << ' ';
		}
//		cerr << endl;
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(g[i][k] + g[k][j] < g[i][j]){
					g[i][j] = g[i][k] + g[k][j];
				}
			}
		}
	}
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= n; j++){
//			cout << g[i][j] << ' ';
//		}cout << '\n';
//	}
	for(int i = 1; i <= q; i++){
		int x, y;
		cin >> x >> y;
		ll ans = 0x3f3f3f3f3f3f3f3f;
		for(auto c1 : mp[x]){
			for(auto c2 : mp[y]){
//				cout << c1[0] << ' ' << c2[0] << ' ' << co[c1[0]][x] << ' ' << co[c2[0]][y] << ' ' << ans << '\n';
				ans = min(ans, co[c1[0]][x] + co[c2[0]][y] + g[c1[0]][c2[0]]);
			}
		}
		cout << w[x] + w[y] + ans << '\n';
	}
	return 0;
}
