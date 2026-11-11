#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
int k[1010], a[1010][1010], t[1010][1010], w[1010];
bool vis[1010][1010];
int sum, ans = INT_MAX, l;

void dfs(int curx, int curz, int des){
	if(a[curx][curz] == des){
		ans = min(ans, sum + t[curx][curz] + l);
		return;
	}
	for(int i = curz + 1; i <= k[curx]; i ++){
		dfs(curx, i, des);
		for(int j = 1; j <= k[a[curx][i]]; j ++){
			if(a[a[curx][i]][j]){
				dfs(a[curx][i], j, des + t[a[curx][i]][a[a[curx][i]][j]]);
			}
		}
	}
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++){ // shijian
		cin >> w[i];
	}
	int maxk = INT_MIN;
	for(int i = 1; i <= n; i ++){ // xianlu
		cin >> k[i];
		for(int j = 1; j <= k[i]; j ++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	int sum = 0;
	for(int i = 0; i < q; i ++){
		int x, y;
		cin >> x >> y;
		sum += w[x] + w[y];
		vector<pair<int, int>> qx;
		qx.clear(); 
		for(int xx = 1; xx <= n; xx ++){
			for(int yy = 1; yy <= k[xx]; yy ++){
				if(a[xx][yy] == x) qx.push_back({xx, yy});
			}
		}
		for(auto p : qx){
			l = t[p.first][p.second];
			dfs(p.first, p.second, y);
		}
		cout << ans + sum << '\n';
	}
	return 0;
}


