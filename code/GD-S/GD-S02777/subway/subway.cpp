#include<bits/stdc++.h>
using namespace std;
const int INF = 1 << 31;
int c,n,m,d,q,w[505],t[505][505],a[505][505],dis[505][505];
vector<vector<int>> e;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++){
		cin >> a[i][0];
		for (int j = 1; j <= a[i][0]; j++){
			cin >> a[i][j];
			cin >> t[i][a[i][j]];
			e[i].push_back(a[i][j]);
		}
		for (int j = 1; j <= n; j++){
			if (!t[i][j]) t[i][j] = INF;
			dis[i][j] = INF;
		}
	}
	if (n <= 200){
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= a[i][0]; j++)
				dis[i][j] = t[i][j];
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++){
					if (i == j) continue;
					dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
				}
		while (q--){
			int x,y;
			cin >> x >> y;
			cout << dis[x][y] + w[x] + w[y] << "\n";
		}
	}
	return 0;
}
