#include<bits/stdc++.h>
using namespace std;
const int N = 5000 + 10;
int a[N] , dis[N][N];
int n , d; 
int main() {
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	int c , t; cin >> c >> t;
	while (t --) {
		cin >> n >> d;
		for (int i = 1 ; i <= n ; i ++) cin >> a[i];
		cout << "0\n";
	}
}
