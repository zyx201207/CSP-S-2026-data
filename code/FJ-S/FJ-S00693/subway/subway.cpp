#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5, M = 505, inf = 1e18;
int c, n, m, d, x, y, q, ans, w[N], f[M][M], k, l, r;

struct note{
	int x, y;
};
vector <note> v[N];

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
    memset(f, 0x3f, sizeof(f));
    for(int i = 1; i <= n; i++) f[i][i] = 0;
	for(int i = 1; i <= n; i++){
		cin >> k;
		for(int j = 1; j <= k; j++) cin >> x >> y, v[x].push_back({i, y});
	}
	for(int i = 1; i <= m; i++)
		for(auto x : v[i]) 
		    for(auto y : v[i])
		    	if(x.x != y.x) f[x.x][y.x] = min(f[x.x][y.x], x.y + y.y);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		    for(int k = 1; k <= n; k++)
			    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while(q--){
		cin >> l >> r;
		ans = inf;
	    for(auto x : v[l]) 
	        for(auto y : v[r]) ans = min(ans, x.y + y.y + f[x.x][y.x]);
		cout << w[l] + w[r] + ans << "\n"; 
	}
 	return 0;
}
