#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define ll long long
#define pii pair<ll, ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
#define N 1000005
#define inf 0x3f3f3f3f3f3f3f3f
#define lowbit(x) (x & -x)

ll c, n, k, a[N], dis[N];
vector<ll> v[N];
queue<pii> q;
bool vis[N];

void dfs(ll x, ll ff, ll S) {
	vis[x] = 1;
	for(auto y : v[x]) if(y != ff && ((S >> y) & 1)) dfs(y, x, S);
}

void dfs(ll x, ll ff) { for(auto y : v[x]) if(y != ff) dis[y] = dis[x] + 1, dfs(y, x); }
ll popc(ll x) { ll res = 0; while(x) res ++, x -= lowbit(x); return res; }

void solution(ll tas) {
	cin >> n >> k;
	rep(i, 0, n - 1) v[i].clear();
	rep(i, 1, n - 1) {
		ll x, y; cin >> x >> y; x --, y --;
		v[x].pb(y), v[y].pb(x);
	}
	ll res = inf;
	rep(S, 0, (1 << n) - 1) if(popc(S) == k) {
		rep(i, 0, n - 1) vis[i] = 0;
		ll cnt = 0, mx = 0;
		rep(i, 0, n - 1) if((S >> i) & 1)
			if(!vis[i]) dfs(i, -1, S), cnt ++;
		if(cnt > 2) continue; 
		rep(i, 0, n - 1) if(!vis[i]) {
			dis[i] = 0, dfs(i, -1); ll x = inf;
			rep(j, 0, n - 1) if(vis[j]) x = min(x, dis[j]);
			mx = max(mx, x);
		}
		res = min(res, mx);
	}
	cout << res << "\n";
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tas = 1; cin >> c >> tas;
	rep(i, 1, tas) solution(i);
	return 0;
}

