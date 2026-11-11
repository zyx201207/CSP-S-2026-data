#include<bits/stdc++.h>
using namespace std;
int op, t;
long long x[2000003], g[5003][5003], ans[5003][5003];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> op >> t;
	while(t--){
		int n;
		long long d;
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
			for(int j = 1; j <= n; j++) g[i][j] = ans[i][j] = 0;
		}
		for(int i = 1; i < n; i++){
			for(int j = i + 1; j <= n; j++){
				if(x[j] - x[i] <= d) g[i][j] = 1;
			}
		}
		for(int len = 3; len <= n; len++){
			for(int i = 1; i <= n - len + 1; i++){
				int j = i + len - 1;
				for(int k = i + 1; k < j; k++){
					if(g[i][k] > 0 && g[k][j] > 0){
						if(g[i][j] == 0 || g[i][j] > g[i][k] + g[k][j]){
							g[i][j] = g[i][k] + g[k][j];
						}
					}
				}
			}
		}
		for(int len = 2; len <= n; len++){
			for(int i = 1; i <= n - len + 1; i++){
				int j = i + len - 1;
				if(j == i + 1 || x[j] - x[i] <= d){
					ans[i][j] = 1;
					continue;
				}
				for(int k = i + 1; k < j; k++){
					if(g[i][k] + g[k][j] == g[i][j]){
						ans[i][j] += ans[i][k] * ans[k][j];
					}
				}
			}
		}
		int cnt = 0;
		for(int i = 1; i < n; i++){
			for(int j = i + 1; j <= n; j++){
				if(ans[i][j] == 2) cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}

