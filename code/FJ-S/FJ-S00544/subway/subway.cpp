#include <bits/stdc++.h>
using namespace std;
int w[500005];
int b[500005];
int vis[500005];
int c[20005][20005];
int qwe, n, m, d, q, k, z = 1e9, s, e;

void dfs(int x, int deq){
	if(x == e){
		z = min(z, deq);
		return;
	}
	for(int i = 1; i <= m; i++){
		if(i != x && c[x][i] != 0 && vis[i] == 0){
			vis[x] = 1;
			dfs(i, deq + c[x][i]);
			vis[x] = 0;
		}
	}
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> qwe >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k;
		for(int j = 1; j <= k; j++){
			int a, x;
			cin >> a >> x;
			b[j] = a;
			for(int k = 1; k <= j; k++){
				c[b[k]][b[j]] = x;
			}
		}
	}
	while(q--){
		cin >> s >> e;
		z = 1e9;
		dfs(s, 0);
		cout << z + w[s] + w[e] + c[s][s] << endl;
	}
	return 0;
}
