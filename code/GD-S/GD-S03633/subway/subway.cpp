
#include <bits/stdc++.h>
using namespace std;

const int M = 5e5 + 5;
int w[M];
int a[505][505];
int t[505][505];
int k[M];
int dis[1005][1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis, 0x3f, sizeof(dis));
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= 2*k[i]; j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	/*for(int i = 1; i <= m; i++){
		for(int j = 1; j <= m; j++){
			for(int p = 1; p <= n; p++){
				if(a[p][i] > 0 && a[p][j] > 0){
					dis[i][j] = min(w[i] + w[j] + t[p][i] + t[] 
				}
			} 
		}
	}
	for(int k = 1; k <= m; k++){
		for(int i = 1; i <= m; i++){
			for(int j = 1;j <= n; j++){
				dis[i][j]=min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}*/
	while(q--){
		int x, y;
		cin >> x >> y;
		int ans = 0;
		bool mx = 0, my = 0;
		int ax, tx, ay, ty;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= k; j++){
				if(a[i][j] == x){
					mx = 1;
					ax = j;
					tx = i;
				}
				if(a[i][j] == y){
					my = 1;
					ay = j;
					ty = i;
				}
			}
		}
		if(mx && my){
			ans = w[x] + w[y] + t[tx][ax] + t[ty][ay];
		}
		cout << ans << "\n"
	}
	return 0;
}

