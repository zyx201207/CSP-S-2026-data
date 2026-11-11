#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
long long c, t, n, d, x[2000005];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 0; i < n; i++){
			cin >> x[i];
		}
		int ans = 0;
		for(int i = 0; i < n - 3; i++){
			int j = i + 3;
			if(x[i + 1] - x[i] <= d && x[j] - x[i + 2] <= d && x[j] - x[i] > d)ans++;
		}
		cout << ans << endl;
	}
	return 0;
} 
