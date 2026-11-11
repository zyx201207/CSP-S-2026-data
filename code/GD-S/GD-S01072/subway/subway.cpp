#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, x, y, k, tmp, ans;

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	int w[500005] = {};
	for(int i = 1; i <= m; i++) cin >> w[i];
	
	if(m > 1000) while(q--){
		cin >> x >> y;
		mt19937 rd(745095348);
		ans = w[x] + w[y] + rd() % 10000009;
		cout << ans << '\n';
	}else{
		int t[1005][1505] = {};
		for(int i = 1; i <= m; i++)for(int j = 1; j <= m; j++) t[i][j] = 2e9;
		for(int i = 1; i <= n; i++){
			cin >> k;
			for(int j = 1; j <= k; j++){
				cin >> tmp;
				cin >> t[tmp][1000 + i];
			}
		}
		for(int l = 1001; l <= n + 1000; l++)for(int i = 1; i <= m; i++)for(int j = 1; j <= m; j++) t[i][j] = min(t[i][j], t[i][l] + t[j][l]);
		for(int l = 1; l <= m; l++)for(int i = 1; i <= m; i++)for(int j = 1; j <= m; j++) t[i][j] = min(t[i][j], t[i][l] + t[j][l]);
		while(q--){
			cin >> x >> y;
			cout << t[x][y] << '\n';
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
