#include <bits/stdc++.h>
using namespace std;

int c , n , m , d , q , k[20202] , r , w[20200] , a[2020][2020] , t[2002][2002] , x[2020] , y[2020] , f , f1 , f2;

int main(){
	freopen("subway.in" , "r" . stdin);
	freopen("subway.out" , "w" . stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1 ; i <= m ; i++) cin >> w[i];
	for (int i = 1 ; i <= n ; i++){
		cin >> k[i];
		for (int j = 1 ; j <= k[i] ; j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1 ; i <= q ; i++){
		cin >> x[i] >> y[i];
	}
	for (int r = 1 ; r <= q ; r++){
		for (int i = 1 ; i <= n ; i++){
			for (int j = 1 ; j <= k[i] ; j++){
				if (a[i][j] == x[r]) f1 = 1;
				if (a[i][j] == y[r]) f2 = 1;
			}
			if (f1 == 1 && f2 == 1){
				cout << w[1] + t[1][1] + t[1][y[r]] + w[y[r]] << "\n";
				break;
			}
		}
	}
	return 0;
}
