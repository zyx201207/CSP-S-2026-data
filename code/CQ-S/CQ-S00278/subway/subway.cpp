#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e7 + 5, INF = 0x3f3f3f3f3f3f3f3f;
bool vis[N];
struct node {
	ll v, w;
};
vector <node> vec[N];
bool operator < (node x, node y) {
	return x.w > y.w;
}
priority_queue <node> q;
ll dis[N];
ll c, n ,m, d, Q;
ll tot_s, cnt;
ll dij(ll s, ll t) {
	for (ll i = 0; i <= cnt; i ++) {
		dis[i] = INF;
		vis[i] = 0;
	}
	q.push({s, 0});
	dis[s] = 0;
	while (! q.empty()) {
		auto now = q.top();
		q.pop();
		if (vis[now.v]) continue;
		vis[now.v] = 1;
		for (auto k : vec[now.v]) {
			if (dis[k.v] > dis[now.v] + k.w) {
				dis[k.v] = dis[now.v] + k.w;

				q.push({k.v, dis[k.v]});
			}
		}
	}
	return dis[t];
}

ll w[N];


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> Q;
	cnt = m;
	for (ll i = 1; i <= m; i ++) {
		cin >> w[i];
	}
	tot_s = m;
	for (ll i = 1; i <= n; i ++) {
		ll k;
		cin >> k;
		ll last = 0;
		for (ll j = 1; j <= k; j ++) {
			ll a, t;
			cin >> a >> t;
//			tot[a] ++;
			cnt ++;
//			tot_s = max(tot_s, a + m * tot[a]);
			vec[cnt].push_back({a, t});
			vec[a].push_back({cnt, t});
//			cout << a + n * tot[a] << endl;
//			cout << "Õ¾Ì¨£º" << a << " " << "Õ¾Ìü£º" << a + n * tot[a] << " " << t << "\n"; 
			if (last != 0) {
				vec[cnt].push_back({last, 0});
				vec[last].push_back({cnt, 0});
			}
			last = cnt;
		}
	}
	while (Q --) {
		
		ll x, y;
		cin >> x >> y;
//		ll tmp = y;
//		while (pre[tmp] != 0) {
//			cout << tmp << " ";
//			tmp = pre[tmp];
//		} 
//		cout << x << "\n";
		cout << dij(x, y) + w[x] + w[y] << "\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
