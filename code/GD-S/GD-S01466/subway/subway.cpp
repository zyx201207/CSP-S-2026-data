#include<iostream>
#define int long long
using namespace std;
int c, n, m, d, q, w[500005], k[505], a[505][505], t[505][505], x, y;
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++) cin >> a[i][j] >> t[505][505];
	}
	while(q--){
		cin >> x >> y;
		
	}
	return 0;
}
