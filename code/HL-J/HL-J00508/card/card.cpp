#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int c[500005];
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	int ans[300005];
	int g[300005];
	for(int i = 0; i < n; i++){
		for(int k = 1; k <= m; k++){
			g[k] = 0;
		}
		int v[300005];
		for(int j = i; j < n; j++){
			if(g[c[j]] < 1){
				g[c[j]] = 1;
				v[c[j]] = j;
			}else{
				for(int k = v[c[j]]; k < j; k++){
					g[c[k]] = 0;
					v[c[k]] = 0;
				}
				v[c[j]] = 1;
				g[c[j]] = 1;
			}
		}
		for(int j = 1; j <= m; j++){
			if(g[j]==1){
				ans[j]++;
			}
		}
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	return 0;
}
