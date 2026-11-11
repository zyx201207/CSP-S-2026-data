#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 5e5 + 5;
int c, n, m, d, q, w[M], ans, l, r;
bool vis[M][505];
struct lu{ 
	int a, t; 
};
vector <lu> ed[505];
void dfs(int now, int u, int spend){
//	cout << now << " " << u << " " << spend << '\n';
	if(u == r){
		ans = min(ans, spend);
		return;
	}
	if(spend >= ans) return;
	vis[now][u] = 1;
	for(int i = 0; i < ed[now].size(); i++){//本铁路线内换乘 
		int v = ed[now][i].a, W = ed[now][i].t;
		if(vis[now][v]) continue;
		dfs(now, v, spend + W);
	}
	for(int i = 1; i <= n; i++){//本站点换乘到其他铁路线 
		if(i == now) continue;
		for(int j = 0; j < ed[i].size(); j++){
			int v = ed[i][j].a, W = ed[i][j].t;
			if(v == u /*&& !vis[now][v]*/){
				dfs(i, u, spend + W);
			}
		}
	}
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		ed[i].clear();
		int k, A, T;
		cin >> k;
		for(int j = 1; j <= k; j++) cin >> A >> T, ed[i].push_back({A, T});
	}
	while(q--){
		cin >> l >> r;
		ans = 1e18; 
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < ed[i].size(); j++){
				int v = ed[i][j].a, W = ed[i][j].t;
				if(v == l){
					for(int k = 1; k <= m; k++)
						for(int l = 1; l <= n; l++)
							vis[k][l] = 0;
					dfs(i, v, W);
				} 
			}
		}
		cout << ans + w[l] + w[r] << '\n';
	}
	return 0;
}
//题外话：这道题读题花的时间快有上道题AC时间长了
//没时间写了，打个爆搜？ 
//神秘复杂度，目测最高12pts 
//T2爆零概率极高，不知道为啥还能从错误地方搜到正解然后先给经过正解的站点排除的……
//释怀了，坐等爆零 
