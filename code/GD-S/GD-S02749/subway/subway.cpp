#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const long long maxm = 5e5+5;
long long c,n,m,d,q;
long long w[maxm];
vector <pair<long long,long long> > routes[maxm];
long long G[505][505];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (long long i = 1;i <= m;i++){
		cin >> w[i];
	}
	for (long long i = 1;i <= n;i++){
		long long k;
		cin >> k;
		for (long long j = 1;j <= k;j++){
			long long a,t;
			cin >> a >> t;
			routes[a].push_back({i,t});
		}
	}
	for (long long i = 1;i <= n;i++){
		for (long long j = 1;j <= n;j++){
			G[i][j] = 1e18;
		}
	}
	for (long long i = 1;i <= n;i++){
		G[i][i] = 0;
	}
	for (long long i = 1;i <= m;i++){
		for (long long j = 0;j < routes[i].size();j++){
			for (long long k = 0;k < routes[i].size();k++){
				if (routes[i][j].first == routes[i][k].first) continue;
				G[routes[i][j].first][routes[i][k].first] = min(G[routes[i][j].first][routes[i][k].first],routes[i][j].second+routes[i][k].second);
				G[routes[i][k].first][routes[i][j].first] = min(G[routes[i][k].first][routes[i][j].first],routes[i][j].second+routes[i][k].second);
			}
		}
	}
	for (long long i = 1;i <= n;i++){
		for (long long j = 1;j <= n;j++){
			for (long long k = 1;k <= n;k++){
				if (i != j and j != k and i != k){
					if (G[i][j] > G[i][k] + G[k][j]){
						G[i][j] = G[i][k] + G[k][j];
					}
					if (G[j][i] > G[j][k] + G[k][i]){
						G[j][i] = G[j][k] + G[k][i];
					}
				}
			}
		}
	}
	while (q--){
		long long x,y;
		cin >> x >> y;
		long long ans = 1e18;
		for (long long i = 0;i < routes[x].size();i++){
			for (long long j = 0;j < routes[y].size();j++){
				ans = min(ans,routes[x][i].second + routes[y][j].second + G[routes[x][i].first][routes[y][j].first]);
			}
		}
		cout << ans + w[x] + w[y] << '\n'; 
	}
}
