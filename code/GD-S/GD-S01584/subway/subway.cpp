#include <bits/stdc++.h>
using namespace std;
const int maxn = 510, maxm = 100010;
int w[maxm], k[maxn], t[maxn][maxm];
bool vis[maxn][maxm];
int c, n, m, d, q;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int f(int x, int y, int ex, int ey){
	if(x == ex && y == ey)return 0;
	int ans = 0x3f3f3f3f;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i], ny = y + dy[i];
		int tx = 1;
		while(tx++ <= m){
			if(!t[x][tx] || vis[x][tx])continue;
			vis[x][tx] = true;
			ans = min(ans, f(x, tx, ex, ey) + t[x][tx]);
			vis[x][tx] = false;
			
		}
		if(nx > n || ny > m || nx <= 0 || ny <= 0 || t[nx][ny] == 0 || vis[nx][ny])continue;
		vis[nx][ny] = true;
		ans = min(ans, f(nx, ny, ex, ey) + t[nx][ny]);
		
		vis[nx][ny] = false;
	}
	return ans;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			int a;
			cin >> a;
			cin >> t[i][a];
		}
	}
	while(q--){
		int st, ed;
		cin >> st >> ed;
		int ns = 0x3f3f3f3f;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(t[i][ed] && t[j][st]){
					ns = min(ns, f(j, st, i, ed) + t[j][st]);
				}
			}
			
		}
		cout << ns + w[st] + w[ed]  << '\n';
	}
	return 0;
}
