#include<bits/stdc++.h>
using namespace std;

const int N = 505;
const int M = 5e5 + 5;
using ll = long long;
int c, n, m, d, q, w[M];

vector<pair<int,int> > sta[M];
ll dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> n >> m >> d >> q;
	for(int i(1); i <= m; i++){
		cin >> w[i];
	}
	int k, x, y, z;
	for(int i(1); i <= n; i++){
		cin >> k;
		while(k--){
			cin >> x >> z;
			sta[x].push_back({i, z});
		}
	}
//	for(int i(1); i <= m; i++) cout << "size=" << sta[i].size() << '\n';
	for(int i(1); i <= n; i++)
		for(int j(i + 1); j <= n; j++)
			dis[i][j] = dis[j][i] = 1e18;
	for(int i(1); i <= m; i++){ //O(md^2)
		for(auto p : sta[i]){
			x = p.first, z = p.second;
			for(auto p2 : sta[i]){
				y = p2.first, k = p2.second;
				if(x != y) 
					dis[x][y] = dis[y][x] = min(dis[x][y], (ll)z + k);
			}
		}
	}
	//Floyd O(n^3)
	for(int k(1); k <= n; k++)
	for(int i(1); i <= n; i++)
	for(int j(1); j <= n; j++)
		dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

	while(q--){ //O(qd^2)
		cin >> x >> y;
		ll ans = 1e18;
		for(auto p1 : sta[x])
			for(auto p2 : sta[y])
				if(dis[p1.first][p2.first] < 1e18)
				ans = min(ans, dis[p1.first][p2.first] + p1.second + p2.second);
		cout << ans + w[x] + w[y] << '\n';
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
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
