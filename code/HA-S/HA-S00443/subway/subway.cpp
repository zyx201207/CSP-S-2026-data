#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q;
long long f[1004][1004],b[1004];
struct subs {
	ll W_;
	ll t_[105];
} a[1005];
vector <ll> w[1005];
ll u[1005][1005];
void dij (ll s) {
	priority_queue<pair<ll,ll> > q;
	for (ll i = 1;i <= n;i ++) f[s][i] = 1e18,b[i] = 0;
	f[s][s] = 0;
	q.push({0,s});
	while (q.size()) {
		ll t = q.top().second;
		q.pop();
		if (b[t]) continue;
		b[t] = 1;
		for (ll i = 0;i < w[t].size();i ++) {
			ll v = w[t][i];
			if (b[v]) continue;
			if (f[s][v] > f[s][t] + u[t][v]) {
				f[s][v] = f[s][t] + u[t][v];
				q.push({-f[s][v],v});
			}
		}
	}
}
int main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (ll i = 1;i <= m;i ++) {
		cin>>a[i].W_;
	}
	for (ll i = 1;i <= m;i ++) {
		for (ll j = 1;j <= m;j ++) u[i][j] = 1e18/2;
	}
	if (c > 8) {
		for (ll i = 1;i <= n;i ++) {
			ll k;
			vector <ll> K;
			cin>>k;
			for (ll j = 1;j <= k;j ++) {
				ll x,p;
				cin>>x>>p;
				a[x].t_[i] = p;
				K.push_back(x);
			}
			for (ll j = 0;j < k;j ++) {
				for (ll r = j + 1;r < k;r ++) {
					ll x = K[j],y = K[r];
					w[x].push_back(y);
					w[y].push_back(x);
					u[x][y] = u[x][y] = min(u[x][y],a[x].t_[i] + a[y].t_[i]);
				}
			}
		}
		for (ll i = 1;i <= m;i ++) dij(i);
	}
	else {
		for (ll i = 1;i <= n;i ++) {
			ll k;
			cin>>k;
			for (ll j = 1;j <= k;j ++) {
				ll x,p;
				cin>>x>>p;
				a[x].t_[i] = p;
			}
		}
		for (ll i = 1;i <= m;i ++) {
			for (ll j = 1;j <= m;j ++) {
				for (ll r = 1;r <= 100;r ++) {
					if (a[i].t_[r] && a[j].t_[r]) {
						u[i][j] = min(u[i][j],a[i].t_[r] + a[j].t_[r]);
					}
				}
			}
		}
		for (ll i = 1;i <= m;i ++) {
			for (ll j = 1;j <= m;j ++) {
				for (ll r = 1;r <= m;r ++) {
					if (u[j][r] > u[i][j] + u[i][r]) {
						u[j][r] = u[i][j] + u[i][r];
					}
				}
			}
		}
	}
	for (ll i = 1;i <= q;i ++) {
		ll x,y;
		cin>>x>>y;
		cout<<u[x][y] + a[x].W_ + a[y].W_<<"\n";
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
