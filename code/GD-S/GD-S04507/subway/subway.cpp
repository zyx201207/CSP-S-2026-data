#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5 , M = 5e5 + 5 , Q = 1e5 + 5;
int c , n , m , d , q;
int w[M] , a[M][N] , t[N][M] , x[Q] , y[Q];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i++){
		cin >> w[i];
	}
	for(int i = 1 ; i <= n ; i++){
		int ki;
		cin >> ki;
		for(int j = 1 ; j <= ki ; j++){
			cin >> a[i][j] >> t[i][j];
			//a:第i条线路经过的第j个地铁站的编号；t:从这个地铁站(Aij)到i的站厅需要的时间 
		}
	}
	for(int i = 1 ; i <= q ; i++){
		cin >> x[i] >> y[i];
	}
	
	return 0;
} 
