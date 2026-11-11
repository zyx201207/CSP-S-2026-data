#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define pii pair<int, int>
#define lowq(type) priority_queue<type, vector<type>, greater<type>>
using namespace std;
const int N = 2e5 +5;
int c, n, m, d, q;
int w[N];
int k[N];
ll dis[5005][5005];
int a[N], t[N];
int mp[505][25005];
ll val[505][25005], val2[505][25005];
bool vis[505][25005];
ll val1[N];
int main () {
	//system("fc .ans my.out");
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	fastio;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	memset(dis, 0x3f, sizeof dis);
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++) {
			cin >> a[j] >> t[j];
			mp[i][j] = a[j];
			vis[i][a[j]] = 1;
			val[i][a[j]] = t[j];
			val2[i][j] = t[j];
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k[i]; j++) {
			for(int K = 1; K <= k[i]; K++) {
				if(j == K) continue;
				//dis[mp[i][j]][mp[i][K]] = dis[mp[i][K]][mp[i][j]] = 0;
				dis[mp[i][j]][mp[i][K]] = val2[i][K] + val2[i][j];
				dis[mp[i][K]][mp[i][j]] = val2[i][j] + val2[i][K];
			}
		}
	}
	for(int i = 1;  i<= n; i++) {
		for(int j = 1; j <= n; j++) {
			ll minn = 1e9;
			if(i == j) continue;
			for(int K = 1; K <= m; K++) {
				if(vis[i][K] && vis[j][K]) {
					minn = min(val[i][K] + val[j][K], minn);
				}
			}
			//	cout << i << " " << j << endl;
			//	cout << minn <<endl;
			if(minn != 1e9) {
				for(int K = 1; K <= k[i]; K++) {
					for(int p = 1; p <= k[j]; p++) {
						//dis[mp[i][K]][mp[j][p]] = dis[mp[j][p]][mp[i][K]] = min(dis[mp[i][K]][mp[j][p]], minn);
						dis[mp[i][K]][mp[j][p]] = min(dis[mp[i][K]][mp[j][p]], minn + val2[j][p] + val2[i][K]);
						dis[mp[j][p]][mp[i][K]] = min(dis[mp[j][p]][mp[i][K]], minn + val2[i][K] + val2[j][p]);
					}
				}
			}

		}
	}
	//cout << dis[2][5] << endl;
	for(int K = 1; K <= m; K ++) {
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= m; j++) {
				dis[i][j] = min(dis[i][j], dis[i][K] + dis[j][K]);
			}
		}
	}
//	memset(val1, 0x3f, sizeof val1);
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= m; j++) {
//			for(int K = 1; K <= m; K++) {
//
//			}
//		}
//	}
	while(q--) {
		int l, r;
		cin >> l >> r;
		cout << dis[l][r] + w[l] + w[r] <<endl;
	}
	return 0;
}

