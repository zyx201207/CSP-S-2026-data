#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;

int c, n, m, d, q;
int w[N];
struct node{
	int id;
	ll w;
};
vector<node> grp[N] = {};

ll dis[505][505] = {};
void malfoy(){
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1;i <= n;i ++) dis[i][i] = 0;
	for (int i = 1;i <= m;i ++){
		for (int j = 0;j < grp[i].size();j ++){
			for (int k = 0;k < grp[i].size();k ++){
				int h = grp[i][j].id, g = grp[i][k].id;
				if (h == g) continue;
			// 	cout << i << " " << h << " " << g << " " << grp[i][j].w << " " << grp[i][k].w << "\n";
				dis[h][g] = min(dis[h][g], grp[i][j].w + grp[i][k].w);
				dis[g][h] = dis[h][g];
			}
		}
	}
	for (int k = 1;k <= n;k ++){
		for (int i = 1;i <= n;i ++){
			for (int j = 1;j <= n;j ++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}

void solve(){
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i ++){
		cin >> w[i];
	}
	for (int i = 1;i <= n;i ++){
		int k;
		cin >> k;
		for (int j = 1;j <= k;j ++){
			int a;
			ll t;
			cin >> a >> t;
			grp[a].push_back({i, t});
		}
	}
	malfoy();
	while (q --){
		int x, y;
		cin >> x >> y;
		ll ans = 0x3f3f3f3f3f3f3f3f; 
		for (node i: grp[x]){
			for (node j: grp[y]){
				ans = min(ans, dis[i.id][j.id] + w[x] + w[y] + i.w + j.w);
			}
		}
		cout << ans << "\n";
	}
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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int t = 1;
	// cin >> t;
	while (t --){
		solve();
	}
	return 0;
}

