#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using pii = pair<int, int>;
const int N = 2e6 + 3;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, T;
	cin >> c >> T;
	while(T--) {
		int n;	ll d;
		cin >> n >> d;
		vector<ll> p(n + 1);
		for(int i = 1; i <= n; ++i) cin >> p[i];
		
		vector<int> pre(n + 1), nxt(n + 1), g[n + 1];
		for(int i = 1; i <= n; ++i) {
			//pre[i] = lower_bound(p.begin() + 1, p.end(), p[i] - d) - p.begin();
			//nxt[i] = upper_bound(p.begin() + 1, p.end(), p[i] + d) - p.begin() - 1;
			for(int j = i + 1; j <= n; ++j) {
				if(p[j] - p[i] > d) break;
				g[i].push_back(j);
			}
		}
		
		int ans = 0;
		for(int i = n; i >= 1; --i) {
			vector<int> dis(n + 1, 0x3f3f3f3f), f(n + 1, 0), done(n + 1);
			priority_queue<pii, vector<pii>, greater<pii>> q;
			q.push({0, i});
			dis[i] = 0; f[i] = 1;
			while(!q.empty()) {
				pii t = q.top();
				q.pop();
				int u = t.second;
				if(done[u]) continue;
				done[u] = 1;
				for(int v : g[u]) {
					if(dis[u] + 1 <= dis[v]) {
						if(dis[u] + 1 == dis[v]) {
							f[v] += f[u];
							continue;
						}
						dis[v] = dis[u] + 1;
						f[v] = f[u];
						q.push({dis[v], v});
					}
				}
			}
			for(int j = i + 1; j <= n; ++j) {
				ans += (f[j] == 2);
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
} 
