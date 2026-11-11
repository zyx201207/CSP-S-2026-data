#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500005], a[505][505], t[505][505];
int dis[500005];
bool inq[500005];
struct edge{
	int to, cost;
};
vector<edge> v[500005];
int spfa(int st, int ed){
	memset(dis, 0x3f, sizeof dis);
	dis [ st ] = 0;
	queue<int> q;
	q.push(st);
	while (!q.empty()){
		int tmp = q.front();
		q.pop();
		inq [ tmp ] = false;
		for (auto e : v [ tmp ]){
			if (dis [ e.to ] > dis [ tmp ] + e.cost){
				dis [ e.to ] = dis [ tmp ] + e.cost;
				if (inq [ e.to ]) continue;
				inq [ e.to ] = true;
				q.push(e.to);
			}
		}
	}
	return dis [ ed ];
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m; ++ i){
		cin >> w [ i ];
	}
	//memset(f, 0x3f, sizeof f);
	for (int i = 1;i <= n; ++ i){
		int num;
		cin >> num;
		for (int j = 1;j <= num; ++ j){
			cin >> a [ i ][ j ] >> t [ i ][ j ];
		}
		for (int j = 1;j <= num; ++ j){
			for (int k = 1;k <= num; ++ k){
				if (k == j) continue;
				v [ a [ i ][ j ] ].push_back({a [ i ][ k ], t [ i ][ j ] + t [ i ][ k ]});
				//v [ a [ i ][ k ] ].push_back({a [ i ][ j ], t [ i ][ j ] + t [ i ][ k ]});
			}
		}
	}
	/*
	for (int i = 1;i <= m; ++ i){
		cout << i << ": ";
		for (auto k : v [ i ]) cout << "[ " << k.to << ", " << k.cost <<" ] ";
		cout << "\n";
	}
	
	for (int k = 1;k <= m; ++ k){
		for (int i = 1;i <= m; ++ i){
			for (int j = 1;j <= m; ++ j){
				f [ i ][ j ] = min(f [ i ][ k ] + f [ k ][ j ], f [ i ][ j ]);
			}
		}
	}
	
	for (int i = 1;i <= m; ++ i){
		for (int j = 1;j <= m; ++ j){
			if (f [ i ][ j ] == 1061109567) cout << -1 << " ";
			else cout << f [ i ][ j ] << " ";
		}
		cout << "\n";
	}
	*/
	while (q --){
		int lp, rp;
		cin >> lp >> rp;
		cout << spfa(lp, rp) + w [ lp ] + w [ rp ] << "\n";
	}
	return 0;
}
