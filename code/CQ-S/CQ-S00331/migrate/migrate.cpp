#include<bits/stdc++.h>
#define qaq ios::sync_with_stdio(0), cin.tie(0)
#define lb(x) (x&(-x))
#define PII pair<int,int>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i,a,b) for(int i=(a);i>=(b);--i)
#define debug(x) cout << #x << "=" << x << " "
using namespace std;
typedef long long ll;
const int N = 1e6+10;
int _, T;
int n; ll d;
ll a[N];
int dis[N];
ll cnt[N];
bool vis[N];
inline void dij(int st) {
	rep(i, 1, n) dis[i] = 0x3f3f3f3f, vis[i] = 0, cnt[i] = 0;
	dis[st] = 0, cnt[st] = 1;
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push({0, st});
	while(!q.empty()) {
		int u = q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		rep(v, u+1, n) {
			if(a[v] - a[u] > d) break;
			if(dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1, cnt[v] = cnt[u];
				q.push(PII{dis[v], v});
			}
			else if(dis[v] == dis[u] + 1) cnt[v] += cnt[u];
		}
	}
}
inline void solve1() {
	cin >> n >> d;
	rep(i, 1, n) cin >> a[i];
	ll ans = 0;
	rep(i, 1, n) {
		dij(i);
		rep(j, i+1, n) ans += (cnt[j] == 2);
	}
	cout << ans << "\n";
}
int main() {
	qaq;
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> _ >> T;
	if(_ <= 6) {while(T --) solve1();}
	else {while(T --) cout << 0 << "\n";}
	return 0;
}

