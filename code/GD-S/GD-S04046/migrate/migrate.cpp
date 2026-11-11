#include <bits/stdc++.h>
using namespace std;
long long o, t, n, m, d, x[2000005], minx = -1e18, ans;
bool flag;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> o >> t;
	while(t--){
		ans = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++){
			cin >> x[i];
		}

		d = x[2] - x[1];
		flag = 1;
		for (int i = 3; i <= n; i++){
			if (d != x[i] - x[i-1]){
				flag = 0;
			}	
		}
		if (flag){
			if (m < d){
				cout << 0;
			}
			else{
				m = m / d;
				if (n-1 <= m){
					cout << 0;
				}
				else{
					bool ok = 1;
					for (int i = 1; i < m && m+i <= n-1; i++){
						ans += n - (m+i+1) + 1;
					}
				}
			}
		}
		else{
			for (int i = 1; i < n; i++){
			 	long long fir = x[i] + m;
			 	flag = 1; 
			 	for (int j = i+1; j <= n && flag; j++){
			 		if (x[j] - x[j-1] > m){
			 			flag = 0;
			 			continue;
					 }
			 		if (x[j] > fir && x[j] < fir + m){
			 			ans++;
				 	}
			 	}
			}
		}
		cout << ans << endl;
	} 
	return 0;
}
