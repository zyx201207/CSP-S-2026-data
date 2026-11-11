#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int k[100005], s[505][100005], t[505][100005], w[100005], ans = 0x3f3f3f3f;
bool vis[100005];
void dfs(int st, int y, int now){
	if(st == y){
		now += (w[y]);
		ans = min(ans, now);
		return;
	}
	for(int i = 1;i <= k[st];i++){
		if(!vis[s[st][i]]){
			vis[s[st][i]] = 1;
			dfs(s[st][i], y, now + t[st][i] + t[i][i]);
			vis[s[st][i]] = 0;
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		scanf("%d", &w[i]);
	}
	for(int i = 1;i <= n;i++){
		scanf("%d", &k[i]);
		for(int j = 1;j <= k[i];j++)scanf("%d%d", &s[i][j], &t[i][j]);
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		memset(vis, 0, sizeof vis);
		vis[x] = 1;
		dfs(x, y, w[x] + t[x][x]);
		cout << ans << '\n';
		ans = 0x3f3f3f3f;
	}
	return 0;
}
