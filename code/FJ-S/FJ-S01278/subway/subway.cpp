#include<bits/stdc++.h>
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;

int T;
const int N = 5e2+5, M = 1e3+5;
int c, n, m, d, q;
int w[M], a[N][M], t[N][M];
int ans[M][M];

void init(int line, int k){
	for(int i=1; i<=k; i++){
		for(int j=i+1; j<=k; j++){
			ans[a[line][i]][a[line][j]] = min(ans[a[line][i]][a[line][j]], w[a[line][i]]+t[line][i]+t[line][j]+w[a[line][j]]);
			ans[a[line][j]][a[line][i]] = ans[a[line][i]][a[line][j]];
		}
	}
}

void solve(){
	cin >> c >> n >> n >> d >> q;
	for(int i=1; i<=m; i++){
		cin >> w[i];
	}
	memset(ans, 0x3f3f3f3f, sizeof(ans));
	for(int i=1; i<=n; i++){
		int k;
		cin >> k;
		for(int j=1; j<=k; j++){
			cin >> a[i][j] >> t[i][j];
		}
		init(i, k);
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		if(ans[x][y] != 0){
			cout << ans[x][y] << endl;
		}else {
			cout << ans[x][y] << endl;
		}
	}
	return;
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	IOS;
	T = 1;
//	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}

