#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> t;
	while(t--){
		int n;
		long long m;
		long long ans = 0;
		cin >> n >> m;
		long long ls1, ls2;
		cin >> ls1 >> ls2;
		for(int i = 3; i <= n; i++){
			int x;
			cin >> x;
		}
		if(ls2 - ls1 <= m){
			ans = (n - 3) * (n - 2) / 2; 
		}
		cout << ans;
	}
	return 0;
} 
