#include<bits/stdc++.h>
using namespace std;
int c, t, n, d, x[5000005];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		int ans = 0, a = x[2] - x[1];
		int al = a / d;
		cout << n - al - 1;
	}
	return 0;
}
