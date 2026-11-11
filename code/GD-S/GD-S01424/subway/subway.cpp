#include<bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, d, k, dis[505][505], a[510000];
struct edge{
	int y, w;
};
vector<edge> G[510000];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> m >> n >> d >> k;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	for(int i = 1;i <= m;i ++){
		int p, pre = 0;
		cin >> p;
		for(int j = 1;j <= p;j ++){
			int x, w;
			cin >> x >> w;
			G[x].push_back((edge){i + n, w});
			G[i + n].push_back((edge){x, w});
		}
	}
	for(int i = 1;i <= m;i ++) for(int j = 1;j <= m; j ++) dis[i][j] = 1e15;
	for(int i = 1;i <= m;i ++) dis[i][i] = 0;
	for(int i = 1;i <= m; i ++){
		for(edge to:G[i + n]){
			for(edge tot:G[to.y]){
				dis[i][tot.y - n] = dis[tot.y - n][i] = min(dis[i][tot.y - n], to.w + tot.w);
			}
		}
	}
	for(int k = 1;k <= m;k ++){
		for(int i = 1;i <= m;i ++){
			for(int j = i + 1;j <= m;j ++){
				dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for(int i = 1;i <= k;i ++){
		int x, y, ans = 1e18;
		cin >> x >> y;
		for(edge j:G[x]){
			for(edge k:G[y]){
				ans = min(ans, dis[j.y - n][k.y - n] + j.w + k.w);
			}
		} 
		cout << ans + a[x] + a[y] << "\n";
	}
	return 0;
}
