//GZ-S00022 云岩区实验中学 向子睿
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 0x3f3f3f3f3f3f3f3fll;
#define fi first
#define se second
#define pii pair<int, int>

int c, n, m, d, q, a, t, x, y, w[500010], k[510], crs[500010][20], cntcrs[500010], dis[510][510];
unordered_map<int, int> v[500];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway6.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= n; i++)dis[i][i] = 0;
	for(int i = 1; i <= m; i++)cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		v[i].rehash(k[i]*20);
		for(int j = 1; j <= k[i]; j++){
			cin >> a >> t;
			for(int l = 1; l < i; l++){
				if(v[l].find(a) != v[l].end()){
					dis[i][l] = min(t + v[l][a], dis[i][l]);
					dis[l][i] = min(t + v[l][a], dis[l][i]);
				}
			}v[i][a] = t;
			crs[a][cntcrs[a]++] = i;
		}
	}
	for(int l = 1; l <= n; l++){
	    for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dis[i][j] = min(dis[i][j], dis[i][l] + dis[l][j]);
            }
	    }
	}
	while(q--){
	    cin >> x >> y;
	    int ans = inf;
        for(int i = 0; i < cntcrs[x]; i++){
            for(int j = 0; j < cntcrs[y]; j++){
                ans = min(ans, dis[crs[x][i]][crs[y][j]] + v[crs[x][i]][x] + v[crs[y][j]][y]);
            }
        }cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
