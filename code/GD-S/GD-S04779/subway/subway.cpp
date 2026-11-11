#include<bits/stdc++.h>
#define ll long long
#define pli pair<ll, int>
using namespace std;
const ll inf = 1e18;
ll c, n, m, d, q, w[500005], dis[505], ans[100005];
vector<pair<int, ll>> cg[505];
vector<pair<int, ll>> ttot[500005];
struct node{
	int l, r, id;
	bool operator<(const node& y) const{
		if(l != y.l) return l < y.l;
		return r < y.r;
	}
}query[100005];
int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	cout.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i) cin >> w[i];
	for(int i = 1; i <= n; ++i){
		int k;
		cin >> k;
		while(k--){
			int a;
			ll t;
			cin >> a >> t;
			for(int p = 0; p < ttot[a].size(); ++p){
				cg[i].push_back({ttot[a][p].first, t+ttot[a][p].second});
				cg[ttot[a][p].first].push_back({i, t+ttot[a][p].second});
			}
			ttot[a].push_back({i, t});
		}
	}
	for(int i = 1; i <= q; ++i){
		int l, r;
		cin >> l >> r;
		query[i] = {l, r, i};
	}
	sort(query+1, query+q+1);
	memset(ans, 0x3f, (q+1)*sizeof(ll));
	for(int i = 1; i <= q; ++i){
		int l = query[i].l, r = query[i].r;
		if(l != query[i-1].l){
			memset(dis, 0x3f, (n+1)*sizeof(ll));
			priority_queue<pli, vector<pli>, greater<pli>> q;
			for(pair<int, ll> t : ttot[l]){
				q.push({t.second, t.first});
				dis[t.first] = t.second;
			}
			while(!q.empty()){
				int u = q.top().second;
				ll d = q.top().first;
				q.pop();
				if(d > dis[u]) continue;
				for(pair<int, ll> t : cg[u]){
					int v = t.first;
					ll w = t.second;
					if(dis[v] > dis[u]+w){
						dis[v] = dis[u]+w;
						q.push({dis[v], v});
					}
				}
			}
		}
		ll qans = inf;
		for(pair<int, ll> t : ttot[r]){
			qans = min(qans, w[l]+w[r]+dis[t.first]+t.second);
		}
		ans[query[i].id] = qans;
	}
	for(int i = 1; i <= q; ++i) cout << ans[i] << '\n';
}
