#include <iostream>
using namespace std;
int n, m, d, q, c, w[20005], x, y, ans, sum, suk[505], sua[505][20005], sut[505][20005], sts[20005][25], stnum[20005];
bool vis[20005];
void dfs(int N){//第N站 
	if (N == y){
		ans = min(ans, sum);
		return;
	}
	for (int i = 1; i <= stnum[N]; i++){//遍历经过的第i条线路
		for (int j = 1; j <= suk[sts[N][i]]; j++){//遍历第i条线路上的第j个站
			if (sua[sts[N][i]][j] == N || vis[sua[sts[N][i]][j]] == true) continue;
			sum += sut[i][j] + sut[sts[N][i]][sua[sts[N][i]][j]];
			vis[sua[sts[N][i]][j]] = true;
			dfs(sua[sts[N][i]][j]);
			sum -= sut[sts[N][i]][j] + sut[sts[N][i]][sua[sts[N][i]][j]];
			vis[sua[sts[N][i]][j]] = false;
		}
	}
	return;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++){
		cin >> suk[i];
		for (int j = 1; j <= suk[i]; j++){
			cin >> sua[i][j] >> sut[i][j];
			stnum[sua[i][j]]++;//经过第sua[i][j]个站的线路数量 
			sts[sua[i][j]][stnum[sua[i][j]]] = i;//第num条经过第sua[i][j]个站的线路号 
		}
	}
	for (int rp = 1; rp <= q; rp++){
		ans = 10000000;
		cin >> x >> y;
		dfs(x);
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
}
