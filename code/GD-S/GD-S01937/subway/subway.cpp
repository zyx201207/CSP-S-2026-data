#include <bits/stdc++.h>
using namespace std;
int c, n, m, dd, q;
int w[500005], k[505];
vector<int> d[500005];//每个点可以去的路线 
vector<int> a[505];//每条路线可以去的点 
vector<int> t[505];//换站时间 
long long f[505][505];
int x, y;
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> dd >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			cin >> x >> y;
			d[x].push_back(i);
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= d[i].size(); j++){
			for(int l = 1; l <= k[d[i][j]]; l++){
//				f[i][a[d[i][j]][l]] = t[d[i][j]]
			}
		}
	}
	return 0;
}
