#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 5, INF = 1e18;
int c, n, m, d, q, w[N], t[5005][5005], mn[N], dis[N];
vector<pii> e[N];
vector<int> a[N];
inline void dij(int s){
	for(int i=0;i<=n*d;i++){
		dis[i] = INF;
	}
	dis[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > q;
	q.push({0, s});
	while(!q.empty()){
		auto t = q.top(); q.pop();
		int d = t.fi, u = t.se;
		if(d != dis[u]) continue;
		for(auto tmp : e[u]){
			int v = tmp.fi, w = tmp.se;
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
			}
		}
	}
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		for(int j=1;j<=k;j++){
			int x, y; cin>>x>>y;
			a[i].push_back(x);
			t[i][x] = y;
			mn[x+(i-1)*d] = y;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<(int)a[i].size()-1;j++){
			e[a[i][j]+(i-1)*d].push_back({a[i][j+1]+(i-1)*d, 0});
			e[a[i][j+1]+(i-1)*d].push_back({a[i][j]+(i-1)*d, 0});
//			cout<<a[i][j]+(i-1)*d<<' '<<a[i][j+1]+(i-1)*d<<' '<<0<<'\n';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=n;k++){
				int a = t[i][k], b = t[j][k];
				if(a == 0 || b == 0) continue;
				e[(i-1)*d+k].push_back({(j-1)*d+k, a + b});
				e[(j-1)*d+k].push_back({(i-1)*d+k, a + b});
//				cout<<(i-1)*d+k<<' '<<(j-1)*d+k<<' '<<a+b<<'\n';
			}
		}
	}
	while(q--){
		int a, b; cin>>a>>b;
		int ask = INF;
		for(int j=1;j<=n;j++){
			dij(a+(j-1)*d);
			int ans = INF;
			for(int i=1;i<=n;i++){
	//			cout<<dis[b+(i-1)*d]<<' '<<mn[b+(i-1)*d]<<'\n';
				if(dis[b+(i-1)*d] >= INF || mn[b+(i-1)*d] >= INF) continue;
				ans = min(dis[b+(i-1)*d] + mn[b+(i-1)*d], ans);
			}
			if(mn[a+(j-1)*d] >= INF) continue;
			ans += w[b] + w[a] + mn[a+(j-1)*d];
			ask = min(ask, ans);
		}
		cout<<ask<<'\n';
	} 
	return 0;
}
/*

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/

