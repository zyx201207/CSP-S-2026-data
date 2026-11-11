#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
int c , d;
long long n , m , q;
long long a[510][510], t[510][510] , w[N] , k[510];
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	while(q--){
		long long x, y;
		cin >> x >> y;
		long long ans = 0;
		ans += w[x];
		int ax , ay;
		for(int i = 1; i <= n; i++){
			int aax , aay;
			for(int j = 1; j <= k[i]; j++){
				if(a[i][j] == x){
					aax = i;
				}
				if(a[i][j] == y){
					aay = i;
				}
			}
			if(aax == aay){
				ax = i;
				ay = i;
			}
		}
		if(ax == ay){
		   ans += t[ax][x];
		   ans += t[ay][y];	
		}
		ans += w[y];
		cout << ans << endl;
	}
	return 0;
}
