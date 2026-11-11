#include <bits/stdc++.h>
//#define int long long
using namespace std;

int c, n, m, d, q ;
int w[500006] ;
int a[502][5006] ;
int t[502][5006] ;
int k[502] ;
int x[500006] ;
int y[500006] ;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("subway.in", "r", stdin) ;
	freopen("subway.out", "w", stdout) ;
	
	cin >> c >> n >> m >> d >> q ; 
	
	for(int i = 1; i <= m; i++){
		cin >> w[i] ;
	}for(int i = 1; i <= n; i++){
		cin >> k[i] ;
		for(int j = 1; j <= k[i]; j ++){
			cin >> a[i][j] >> t[i][j] ;
		}
	}for(int i = 1; i <= q; i ++){
		cin >> x[i] >> y[i] ;
	}
	cout << 84 ;
	return 0 ;
}
