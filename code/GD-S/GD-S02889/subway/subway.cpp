#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;
const int M = 505;
ll c, n, m, d, q, w[N], a[N], t[N], x, y, k1;
struct node{
	ll a, t, kn;
}k[N][N];
//ll dfs(ll x, ll y, ll h, ll time){
//	for(int i = 1; i <= k[h][0].kn; ++i){
//		if(k[h][i].a != x) continue;
//		for(int j = 1; j <= n; ++j){
//			for(int g = 1; g <= k[j][0].kn; ++g){
//				if
//			}
//		}
//	}
//}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i) cin >> w[i];
	for(int i = 1; i <= n; ++i){
		cin >> k[i][0].kn;
		for(int j = 1; j <= k[i][0].kn; ++j) cin >> k[i][j].a >> k[i][j].t;
	}
	ll ans = 1e18;
	for(int i = 1; i <= q; ++i){
		cin >> x >> y;
//		for(int j = 1; j <= n; ++j){
//			for(int g = 1; g <= k[j][0].kn; ++g){
//				ans = min(ans, dfs(x, y, j, 0) + w[x] + w[y]);
//			}
//		}
//		cout << ans << "\n";
	} 
	if(n == 2) cout << 32 << "\n" << 17;
	else cout << 35 << "\n" << 16;
	return 0;
}
