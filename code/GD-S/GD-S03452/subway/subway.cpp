#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+5, M = 505;
ll c, n, m, d, q;
ll w[N];
ll mp[M][M]; //mp存缩点后的图 
vector<pair<int, ll>> bridge[N]; //每个节点可看作一个桥，连接多条线路
ll dist[M][M]; //迪杰斯特拉距离数组

void Dijkstra(int start){
	priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
	pq.push({0, start});
	dist[start][start] = 0;
	while(!pq.empty()){
		auto [d, x] = pq.top();
		pq.pop();
		//cout << start << ' ' << x << ':' << d << endl;
		for(int i=1;i<=n;++i){
			if(mp[x][i]==0 || i==start || (d+mp[x][i]>dist[start][i] && dist[start][i]!=0)) continue;
			dist[start][i] = d+mp[x][i];
			pq.push({dist[start][i], i});
		}
	}
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;++i) cin >> w[i];
	for(int i=1;i<=n;++i){
		ll k;
		cin >> k;
		for(int j=1;j<=k;++j){
			ll sta, t;
			cin >> sta >> t;
			bridge[sta].push_back({i, t});
		}
	}
	for(int i=1;i<=m;++i){ //利用"桥"缩点，已知d不会超过20，这里不会超时 
		for(int st=0;st<bridge[i].size()-1;++st){
			for(int ed=st+1;ed<bridge[i].size();++ed){
				auto [st_l, st_t] = bridge[i][st];
				auto [ed_l, ed_t] = bridge[i][ed];
				if(mp[st_l][ed_l]==0) mp[st_l][ed_l] = mp[ed_l][st_l] = st_t+ed_t;
				else mp[st_l][ed_l] = mp[ed_l][st_l] = min(mp[st_l][ed_l], st_t+ed_t);
			}
		}
	}
	for(int i=1;i<=n;++i) //缩点跑最短路，离线预处理加速后面查询 
		Dijkstra(i);
	/*for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cout << dist[i][j] << ' ';
		}
		cout << endl;
	}*/
	while(q--){
		int st, ed;
		cin >> st >> ed;
		ll ans = 1e18;
		for(auto [a, t_a]:bridge[st]){
			for(auto [b, t_b]:bridge[ed]){
				ans = min(ans, dist[a][b]+t_a+w[st]+t_b+w[ed]);
			}
		}
		cout << ans << endl;
	}
	
	return 0;
} 
