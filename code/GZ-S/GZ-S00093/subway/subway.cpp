//×ñÒåËÄÖÐ ÑîºÆ³½ GZ-S00093
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
ll w[N], k[1005], kk[1005][1005], a[1005][1005], p=1e9;
struct node {
	ll v, w;
};
vector<node> g[100005];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c, n, m, d, q;
	cin >> c >> n >>  m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> kk[i][j];
			p = min(p, kk[i][j]);
		}
		if (k[i]==2) {
			g[a[i][1]].push_back({a[i][2],w[a[i][1]]+w[a[i][2]]+kk[i][1]+kk[i][2]});
			g[a[i][2]].push_back({a[i][1],w[a[i][2]]+w[a[i][1]]+kk[i][2]+kk[i][1]});
		}
	}
	if (n==1) {
		while (q--) {
			ll x, y;
			cin >> x >> y;
			ll m1=1e9, m2=0;
			for (int i = 1; i <= n; i++) {
				m1 = min(m1,w[i]);
			}
			cout << m1 + p << endl;
		} 
	} else {
		while(q--) {
			ll x, y;
			cin >> x >> y;
			if (x == y) {
				ll m1=1e9, m2=0;
				for (int i = 1; i <= n; i++) {
					m1 = min(m1,w[i]);
				}
				cout << m1 + p;
			} else {
				ll m2 = 1e9;
				for (auto u:g[1]) {
					m2 = min(m2,u.w);
				}
				cout << m2;
			}
			cout << endl;
		} 
	}
	return 0;
}

