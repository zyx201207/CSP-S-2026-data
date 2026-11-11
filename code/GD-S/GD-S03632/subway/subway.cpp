#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define cfalse cin.tie(0)->sync_with_stdio(0)
const int maxn = 1e4 + 5;
const int inf = 1e18;
int c, n, m, d, q;
int w[4000005], dis[4000005];
struct node{
	int v, w;
	bool operator<(const node& a)const{
		return a.w < w;
	}
};
vector<node>mp[4000005];
bool vis[4000005];
void dij(int s){
	priority_queue<node>q;
	q.push({s, 0});
	for(int i = 1; i <= 2 * m; i++){
		vis[i] = 0;
		dis[i] = inf;
	}
	while(!q.empty()){
		auto p = q.top();
		q.pop();
		if(vis[p.v]) continue;
		vis[p.v] = 1;
		dis[p.v] = p.w;
		for(auto i : mp[p.v]){
			if(dis[i.v] > dis[p.v] + i.w){
				dis[i.v] = dis[p.v] + i.w;
				q.push({i.v, dis[i.v]});
			}
		} 
	} 
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
    cfalse;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= 2 * m; i++){
    	dis[i] = inf;
	}
//	cin >> n >> m >> q; 
    for(int i = 1; i <= m; i++){
    	cin >> w[i];
	}
	int cnt = m + 1;
	for(int i = 0; i < n; i++){
		int k; cin >> k;
		for(int j = 0; j < k; j++){
			int v, w; cin >> v >> w;
			mp[v].push_back({cnt, w});	
			mp[cnt].push_back({v, w});
//			f[cnt][v] = f[v][cnt] = w;
		}
		cnt++;
	}
//	for(int i = 0; i < m; i++){
//		int u, v, w; cin >> u >> v >> w;
//		f[u][v] = f[v][u] = w;
//	}
//	for(int i = 1; i <= m; i++){
//		dij(i);
//	}
//	for(int i = 1; i <= m; i++) cout << w[i] << ' ';
//	cout << endl;
//	for(int i = 1; i <= m; i++){
//		cout << i << ": " << endl;
//		for(auto j : mp[i]){
//			cout << j.v << ' ' << j.w << endl;
//		}
//	}
	for(int i = 0; i < q; i++){
		int u, v; cin >> u >> v;
		dij(u);
		int ans = w[u] + w[v] + dis[v];
		cout << ans << endl;
	}
    return 0;
}
