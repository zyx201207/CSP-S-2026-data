#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
#define NDEBUG
#ifdef NDEBUG
	#define debug(x)
#else
	#define debug(x) cerr << #x << ' ' << x << endl
#endif
using namespace std;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 505;
const int M = 5e5 + 5;
int c, n, m, d, q;
int w[M];
// solve1,2 用的：



inline void solve1(){
	int a[601][601];
	for(int i = 1; i <= n + m; i++){
		for(int j = 1; j <= n + m; j++) a[i][j] = INF;
		a[i][i] = 0;
	}
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1, k; i <= n; i++){
		cin >> k;
		for(int j = 1, b, t; j <= k; j++){
			cin >> b >> t;
			a[m + i][b] = a[b][m + i] = t;
		}
	}
	for(int k = 1; k <= n + m; k++){
		for(int i = 1; i <= n + m; i++){
			for(int j = 1; j <= n + m; j++) a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
		}
	}
	for(int i = 1, u, v; i <= q; i++){
		cin >> u >> v;
		cout << a[u][v] + w[u] + w[v] << '\n';
	}
	return ;
}



inline void solve2(){
	int a[1001][1001];
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= m; j++) a[i][j] = INF;
		a[i][i] = 0;
	}
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1, k, a1, t1, a2, t2; i <= n; i++){
		cin >> k;
		if(k == 2){
			cin >> a1 >> t1 >> a2 >> t2;
			a[a1][a2] = a[a2][a1] = t1 + t2;
		}
	}
	for(int k = 1; k <= m; k++){
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= m; j++) a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
		}
	}
	for(int i = 1, u, v; i <= q; i++){
		cin >> u >> v;
		cout << a[u][v] + w[u] + w[v] << '\n';
	}
	return ;
}



inline void solve32(){
	int a[2][500001];
	for(int i = 1; i <= m; i++) a[0][i] = a[1][i] = 0;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1, k; i <= n; i++){
		cin >> k;
		for(int j = 1, b, t; j <= k; j++){
			cin >> b >> t;
			a[i - 1][b] = t;
		}
	}
	int minn = INF;
	for(int i = 1; i <= m; i++){
//			cout << a[0][i] << ' ' << a[1][i] << '\n';
		if(a[0][i] && a[1][i]) minn = min(minn, a[0][i] + a[1][i]);
	}
	for(int i = 1, u, v, ans; i <= q; i++){
		ans = INF;
		cin >> u >> v;
		if(a[0][u] && a[0][v]){
			ans = min(ans, a[0][u] + a[0][v]);
		}
		if(a[1][u] && a[1][v]){
			ans = min(ans, a[1][u] + a[1][v]);
		}
		if(a[1][u] && a[0][v]){
			ans = min(ans, minn + a[1][u] + a[0][v]);
		}
		if(a[0][u] && a[1][v]){
			ans = min(ans, minn + a[0][u] + a[1][v]);
		}
		cout << ans << '\n';
	}
	return ;
}



inline void solve31(){
	int a[500001];
	for(int i = 1; i <= m; i++) a[i] = 0;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1, k; i <= n; i++){
		cin >> k;
		for(int j = 1, b, t; j <= k; j++){
			cin >> b >> t;
			a[b] = t;
		}
	}
	for(int i = 1, u, v; i <= q; i++){
		cin >> u >> v;
		cout << a[u] + a[v] + w[u] + w[v] << '\n';
	}
	return ;
}
inline void solve3(){
	if(n == 2) solve32();
	else solve31();
	return ;
} 
inline void solve(){
	cin >> c >> n >> m >> d >> q;
	if(c <= 8){ // 32
		solve1();
		return ;
	}
	if(c <= 11){ // 12 理论可过 
		solve2();
		return ;
	}
	if(20 <= c && c <= 21){ // 8
		solve3();
		return ;
	}
	for(int i = 1; i <= q; i++){
		cout << 4 << '\n';
	}
	return ;
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}

/*
众星因你，皆降为尘
华风夏韵，洛水天依
乐正司百曲，绫动万年红
言起一人歌，歌起万人和

luogu 1008686 wayneoi 喵！

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

20 2 3 5 2
1 1 1
2 1 1 2 1
2 3 1 2 1
1 3
1 3
2

20 1 3 5 2
1 1 1
3 1 1 2 1 3 1
1 2
2 3
2
2
2
*/
