#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define fi first
#define se second
using namespace std;
ll c, n, m, d, q, w[500005], sz[505], dis[505][505];
vector<pii> ed[505];
vector<pii> nd[500005];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dis, 0x3f, sizeof(dis));
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> sz[i];
		for(int j = 1;j <= sz[i];j++){
			ll a, t;
			cin >> a >> t;
			nd[a].push_back({i, t});
		}
		dis[i][i] = 0;
	}
	for(int i = 1;i <= m;i++){
		for(int j = 0;j < nd[i].size();j++){
			for(int k = 0;k < nd[i].size();k++){
				dis[nd[i][j].fi][nd[i][k].fi] = min(dis[nd[i][j].fi][nd[i][k].fi], nd[i][j].se + nd[i][k].se);
				dis[nd[i][k].fi][nd[i][j].fi] = dis[nd[i][j].fi][nd[i][k].fi];
			}
		}
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(dis[i][k] <= 1e18 && dis[k][j] <= 1e18){
					if(dis[i][j] > 1e18){
						dis[i][j] = dis[i][k] + dis[k][j];
					}
					else{
						dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
					}
					dis[j][i] = dis[i][j];
				}
			}
		}
	}
	while(q--){
		ll x, y, ans = 0, tmp = 1e18;
		cin >> x >> y;
		ans += w[x] + w[y];
		for(int i = 0;i < nd[x].size();i++){
			for(int j = 0;j < nd[y].size();j++){
				ll sum = nd[x][i].se + nd[y][j].se;
				tmp = min(tmp, sum + dis[nd[x][i].fi][nd[y][j].fi]);
			}
		}
		cout << ans + tmp << '\n';
	}
	return 0;
}
