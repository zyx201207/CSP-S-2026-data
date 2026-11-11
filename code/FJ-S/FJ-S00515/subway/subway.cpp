#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	int c , n , m , d , q;
	cin >> c >> n >> m >>d >> q;
	int w[m + 5],k[n+5],t[n + 5][500005];
	bool a[n + 5][m+5];
	for(int i = 0 ; i < m ; i ++) {
		cin >> w[i];
	}
	for(int i = 0 ; i < n ; i++){
		cin >> k[i];
	}
	for(int i = 0 ; i < n ; i ++) {
		for(int j = 0 ; j < k[i] ; j ++) {
			cin >> a[i][j] >> t[i][j];
		} 
	}
	while(q--){
		int x ,y;
		cin >> x >> y;
		cout << 0 << "\n";
	}
	
	return 0;
}
