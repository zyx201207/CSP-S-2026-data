#include<bits/stdc++.h>
using namespace std;

const int N = 5010;

ll x[N], dist[N][N];

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int _, T;
	cin >> _ >> T;
	while(T--){
		int n, d;
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
		}	
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j){
					continue;
				}
				dist[i][j] = abs(x[i] - x[j]);
			}
		}
		int ans = 0;
		for(int u = 1; u <= n; u++){
			for(int v = 1; v <= n; v++){
				if(u == v){
					continue;
				}
				if(dist[u][v] <= d){
					continue;
				}else{
					
				}
			}
		}
	}
	return 0;
}
