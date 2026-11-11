#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500010, INF = 1e18;
namespace cza{
	int Cid;
	int n, m, d, q;
	int w[N];
	vector<pair<int, int> > ve[N];
	int dis[505][505];
	int main(){
		freopen("subway.in", "r", stdin);
		freopen("subway.out", "w", stdout);
		ios::sync_with_stdio(0), cin. tie(0), cout. tie(0);
		cin >> Cid >> n >> m >> d >> q;
		for(int i = 1; i <= m; i++){
			cin >> w[i];
		}
		memset(dis, 0x3f, sizeof dis);
		for(int i = 1; i <= n; i++){
			dis[i][i] = 0;
		}
		for(int i = 1, k; i <= n; i++){
			cin >> k;
			while(k--){
				int a, t;
				cin >> a >> t;
				for(pair<int, int> pr : ve[a]){
					dis[pr. first][i] = min(dis[pr. first][i], pr. second + t);
					dis[i][pr. first] = dis[pr. first][i];
				}
				ve[a]. push_back({i, t});
			}
		}
		for(int i = 1; i <= n; i++){
			for(int k = 1; k <= n; k++){
				for(int j = 1; j <= n; j++){
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
		while(q--){
			int x, y;
			cin >> x >> y;
			int ans = INF;
			for(pair<int, int> prx : ve[x]){
				for(pair<int, int> pry : ve[y]){
					ans = min(ans, prx. second + dis[prx. first][pry. first] + pry. second);
				}
			}
			cout << w[x] + ans + w[y] << '\n';
		}
		return 0;  
	}
}
signed main(){
	return cza::main();
}
