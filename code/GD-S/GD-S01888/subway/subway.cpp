#include<bits/stdc++.h>
#define int long long
using namespace std;
int c , n , m , d , q;
int len[505] , w[500005];
vector<int> zhan[505] , tim[505];
vector<pair<int , int> > metro[500005];
int dis[505][505];
signed main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i++) cin >> w[i];
	for(int i = 1 ; i <= n ; i++){
		cin >> len[i];
		for(int j = 1 ; j <= len[i] ; j++){
			int x , y;
			cin >> x >> y;
			zhan[i].push_back(x);
			tim[i].push_back(y);
			metro[x].push_back({i , y}); 
		}
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(i == j) dis[i][j] = 0;
			else dis[i][j] = 1e15;
		}
	}
	for(int i = 1 ; i <= m ; i++){
		for(int j = 0 ; j < metro[i].size() ; j++){
			for(int k = j + 1 ; k < metro[i].size() ; k++){
				dis[metro[i][j].first][metro[i][k].first] = metro[i][j].second + metro[i][k].second;
				dis[metro[i][k].first][metro[i][j].first] = metro[i][j].second + metro[i][k].second;
			} 
		}
	}
	for(int k = 1 ; k <= n ; k++){
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ; j++){
				dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
			}
		} 
	}
//	for(int i = 1 ; i <= n ; i++){
//		for(int j = 1 ; j <= n ; j++){
//			cout << dis[i][j] << " ";
//		}
//		cout << "\n";
//	}
	while(q--){
		int x , y , ans = 1e15;
		cin >> x >> y;
		for(int i = 0 ; i < metro[x].size() ; i++){
			for(int j = 0 ; j < metro[y].size() ; j++){
				ans = min(ans , dis[metro[x][i].first][metro[y][j].first] + metro[x][i].second + metro[y][j].second + w[x] + w[y]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
