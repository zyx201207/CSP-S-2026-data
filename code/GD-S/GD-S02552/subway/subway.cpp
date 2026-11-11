#include <iostream>
#include <vector>
using ll = long long;
using namespace std;
const ll N = 5e5 + 5e2 + 10, INF = 0x3f3f3f3f3f3f3f3f;
ll w[N];
struct node{
	ll u_, t_;
}; 
vector<node> mp[N];
/*
对于 vector: mp[i]:
1、若 1 <= i <= m , 则 mp[i][j] 代表地铁站厅 i 与 站台 mp[i][j].u_ 有 mp[i][j].t_ 的路程
2、若 n <  i      , 则 mp[i][j] 代表地铁线路 i 与 站厅 mp[i][j].u_ 有 mp[i][j].t_ 的路程 
*/
ll dis[N]; // dis[i][j] 中 1 <= n + m 为实际使用范围 
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(ll i = 1; i <= m; i++) cin >> w[i];
	for(ll i = 1; i <= n; i++){
		ll k;
		cin >> k;
		for(ll j = 1; j <= k; j++){
			ll u, v;
			cin >> u >> v;
			mp[i + m].push_back({u, v});
			mp[u].push_back({i + m, v});
		}
	}
	/*
	for(ll i = 1; i <= m; i++){
		for(auto j : mp[i]){
			cout << "站厅" << i << " 连 " << "线路" << j.u_ - m<< " 耗时" << j.t_ << '\n'; 
		}
	}
	cout << '\n'; 
	for(ll i = 1; i <= n; i++){
		for(auto j : mp[i + m]){
			cout << "线路" << i << " 连 " << "站厅" << j.u_ << " 耗时" << j.t_ << '\n'; 
		}
	}
	*/
	bool vis[N];
	while(q--){
		dis[n + m + 1] = INF;
		for(ll i = 1; i <= n + m; i++) dis[i] = INF;
		for(ll i = 1; i <= n + m; i++) vis[i] = 0;
		ll x, y;
		cin >> x >> y;
		ll time = w[x] + w[y];
		dis[x] = 0;
		for(ll a_____ = 1; a_____ <= n + m; a_____++){
			ll fr = n + m + 1;
			for(ll j = 1; j <= n + m; j++)
				if(!vis[j] && dis[j] <= dis[fr])
					fr = j;
			vis[fr] = 1;
			for(auto avlble : mp[fr]){
				dis[avlble.u_] = min(dis[avlble.u_], dis[fr] + avlble.t_);
			}
		}
		cout << dis[y] + time << '\n';
	}
	return 0;
} 
