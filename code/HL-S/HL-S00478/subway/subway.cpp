#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int A = 505;
const int K = 2e3+5;
vector<vector< P > > g(K);
int w[A],a[A][K] , t[A][K] , k[K],dis[A] , vis[A];
int c, n ,m ,d, q;
int dij(int s , int to){
	priority_queue<P , vector< P > , greater< P > >q;
	q.push({0 , s});
	dis[s] = 0;
	while(!q.empty()){
		auto [u , len] = q.top();
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto [v , w] : g[u]){
			if(dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				q.push({dis[v] , v});
			}
		}
	}
	return dis[to];
}
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++) cin >> w[i];
	for(int i = 1;i <= n;i ++){
		cin >> k[i];
		for(int x = 1;x <= k[i];x ++){
			cin >> a[i][x] >> t[i][x];
			g[i].push_back({a[i][x] , t[i][x]});
		}
	}
	while(q--){
		memset(dis , 0x3f , sizeof(dis));
		memset(vis , 0 , sizeof(vis));
		int x,y , ans = 0;
		cin >> x >> y;
		ans += (w[x] + w[y]);
		//ans += dij(x , y);
		for(int  i  = x;i <= y;i ++) ans += t[i][i]+t[i][i + 1];
		cout << ans << '\n';
	}
	return 0;
}