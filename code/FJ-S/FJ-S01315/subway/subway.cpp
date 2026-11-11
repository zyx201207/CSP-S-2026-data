#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
int kc[750], t[200][maxn], l[maxn][200], id[maxn][200], k[maxn], cc[maxn], vis[maxn];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, g;
	cin >> c >> n >> m >> d >> g;
	memset(vis,0x3f, sizeof vis); 
	for(int i = 1; i <= m; i++) cin >> k[i];
	for(int i = 1; i <= n; i++){
		cin >> kc[i];
		for(int j = 1; j <= kc[i]; j++){
			int lm;
			cin >> t[i][j] >> lm;
			cc[t[i][j]]++;
			id[t[i][j]][cc[t[i][j]]] = i;
			l[t[i][j]][i] = lm;
		}
	}
	
	while(g--){
		int x, y;
		cin >> x >> y;
		if(id[x][1] == id[y][1]){
			int u = id[x][1];
			cout << k[x]+k[y]+l[x][u]+l[y][u] << endl;
		}else{
			int uu = id[x][1], vv = id[y][1];
			int ans = k[x]+k[y]+l[x][uu]+l[y][vv], mi=INT_MAX;
			for(int i = 1; i <= m; i++){
				if(cc[i] > 1){
					int u = id[i][1], v = id[i][2];
					mi = min(mi,l[i][u]+l[i][v]);
				}
			}
			ans += mi;
			cout << ans << endl;
		}
	}
	return 0;
}
