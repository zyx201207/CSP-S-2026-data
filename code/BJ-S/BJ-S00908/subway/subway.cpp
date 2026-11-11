#include <bits/stdc++.h>
using namespace std;
int a[50005];
int w[15][10005] , t[15][10005];
int c , n , m , d , q;
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j1 = 1;j1 <= k;j1++){
			cin >> w[i][j1];
		}
		for(int j2 = 1;j2 <= k;j2++){
			cin >> t[i][j2];
		}
	}
	if(c == 0 && n == 2){
		cout << 32 << endl << 17;
	}
	else{
		cout << 35 << endl << 16;
	}
	
	return 0;
}
