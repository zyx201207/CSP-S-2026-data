#include <bits/stdc++.h>
using namespace std;

const int lim = 2;
int c, T, n, d;
int sum, len;
vector<int> x;

void dfs(int u, int v, int stp){
	int dt = v - u, dlim;
	dlim = dt / d + 1;
	if(u == v && stp == dlim){
		len++;
		return;
	}
	if(u > v){
		return;
	}
	
	for(int i = 1; i <= d; i++){
		for(auto k : x){
			if(k == u + i){
				dfs(u + i, v, stp + 1);
				break;
			}
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> T;
	while(T--){
		sum = len = 0;
		x.clear();
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			int xi;
			cin >> xi;
			x.push_back(xi);
		}
		if(n == 2){
			cout << 0 << "\n";
			continue;
		}else{
			for(int i = 1; i <= n; i++){
				for(int j = i + 2; j <= n; j++){
					dfs(x[i - 1], x[j - 1], 0);
					if(len == lim){
						sum++;
					}
				}
			}
		}
		cout << sum << "\n";
	}
	
	return 0; 
}
