#include<bits/stdc++.h>
using namespace std;
int op, n, m, d, q, w[5003], a[5003], t[5003];
long long g[5003][5003];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> op >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> a[j] >> t[j];
		}
		for(int j = 1; j < k; j++){
			for(int p = j + 1; p <= k; p++){
				if(t[j] + t[p] < g[a[j]][a[p]] || g[a[j]][a[p]] == 0){
					g[a[p]][a[j]] = g[a[j]][a[p]] = t[j] + t[p];
				}
			}
		}
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= m; j++){
			for(int k = 1; k <= m; k++){
				if(j == k || i == k) continue;
				if(g[i][j] == 0 || g[j][k] == 0) continue;
				if(g[i][k] == 0 || g[i][k] > g[i][j] + g[j][k]){
					g[i][k] = g[k][i] = g[i][j] + g[j][k];
				}
			}
		}
	}
	for(int i = 1; i <= q; i++){
		int x, y;
		cin >> x >> y;
		cout << g[x][y] + w[x] + w[y] << endl;
	}
	return 0;
}

