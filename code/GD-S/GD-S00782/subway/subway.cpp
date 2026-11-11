#include <bits/stdc++.h>
using namespace std;
#define int long long
int w[500010], val[500010][30];
vector<int> e[500010], p[510];
vector<pair<int, int> > a[510];
int dis[510][510];
void dijk(int st){
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	q.push({0, st});
	dis[st][st]=0;
	while(!q.empty()){
		int u=q.top().second, x=q.top().first;
//		cout << u << " ";
		q.pop();
		if(x>dis[st][u]) continue;
		for(pair<int, int> num:a[u]){
			int v=num.first;
			int w=num.second;
			if(dis[st][u]+w<dis[st][v]){
				dis[st][v]=dis[st][u]+w;
				q.push({dis[st][v], v});
			}
		}
	}
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dis, 0x3f, sizeof(dis));
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int num;
			cin >> num;
			e[num].push_back(i);
			p[i].push_back(num);
			cin >> val[num][i];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int v:p[i]){
			if(e[v].size()>1){
				for(int x:e[v]){
					a[i].push_back({x, val[v][i]+val[v][x]});
				}
			}
		}
	}
	for(int i = 1; i <= n; i++){
		dijk(i);
//		cout << "\n";
	}
//	for(int i = 1; i <= n; i++){
//		for(pair<int, int> x:a[i]){
//			cout << i << " " << x.first << " " << x.second << "\n";
//		}
//	}
//	cout << "\n";
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= n; j++){
//			cout << i << " " << j << " " << dis[i][j] << "\n";
//		}
//	}
	while(q--){
		int l, r;
		cin >> l >> r;
		int ans=1e18;
		for(int u:e[l]){
			for(int v:e[r]){
				int x=w[l]+w[r]+val[l][u]+val[r][v]+dis[u][v];
				ans=min(ans, x);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
