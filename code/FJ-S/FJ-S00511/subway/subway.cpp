// Õº¡È±£””Œ“ rp += INF Wrong Answer -= INF Accepted = |tan 90| 
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505, M = 5e5 + 10;
int c, n, m, d, q;
vector<int> a[N], t[N];
vector<pair<int, int> > r[M];
int w[M], k[N];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		a[i].reserve(k[i] + 1);
		t[i].reserve(k[i] + 1);
		for(int j = 1; j <= k[i]; j++){
			cin >> a[i][j] >> t[i][j];
			r[a[i][j]].push_back({i, t[i][j]});
		}
	}
	while(q--){
		int x, y; cin >> x >> y;
		int ans1 = w[x] + w[y];
		cout << w[x] + w[y] << '\n';
	}
}
