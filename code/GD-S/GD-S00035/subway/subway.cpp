#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, x, y, sum;
vector<int> w, k;
vector<vector<int> > a, t;

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	w.resize(m + 1), k.resize(n + 1);
	a.resize(n + 1), t.resize(n + 1);
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		a[i].resize(k[i] + 1), t[i].resize(k[i] + 1);
		for(int j = 1; j <= 2 * k[i]; j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int r = 1; r <= q; r++){
		cin >> x >> y;
	}
	return 0;
} 
