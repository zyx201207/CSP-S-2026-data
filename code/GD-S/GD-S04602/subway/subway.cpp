#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int c,n,m,d,q;
ll w[N],k[N],rx[N],ry[N];
struct node {
	int id;
	ll w;
};
vector<node> g[N],f[N];


int main () {
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) cin >> w[i];
	for(int i = 1; i <= n; i ++) {
		cin >> k[i];
		for(int j = 1; j <= k[i]; j ++) {
			int u,tu;
			cin >> u >> tu;
			g[i].push_back({u,tu});
			f[u].push_back({i,tu});
		}
	}
	for(int i = 1; i <= q; i ++) {
		int x,y;
		cin >> x >> y;
		cout << w[x] + w[y] << endl;
	}
	return 0;
}
