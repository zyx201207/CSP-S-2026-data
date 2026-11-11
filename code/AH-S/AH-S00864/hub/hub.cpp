#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N =1E5 + 5;
LL c,t,n,k, DIS[N], MOD = 0x3f3f3f3f3f3f3f3f, u, v;
bool vis[N];
vector<LL> g[N],dis[N];
struct node {
	LL to, w;
	bool operator < (const node &rhx) const {
		return w > rhx.w;
	}
};
void djs(int x) {
	priority_queue<node> pq;
	pq.push({x, 0}),DIS[x] = 0;
	while (!pq.empty()) {
		node pos = pq.top(); pq.pop();
		if (vis[pos.to]) continue;
		vis[pos.to] = true;
		int len = g[pos.to].size();
		for (int i =0; i < len; i ++) {
			int t = g[pos.to][i];
			if (!vis[t] && DIS[pos.to] + 1 < DIS[t]) {
				DIS[t] = DIS[pos.to] + 1;
				pq.push({t,DIS[t]});
			}
		}
	}
}
int main() {
	freopen("hub.in","r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >>c>>t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i < n; i ++) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for (int i = 1; i <= n; i ++){
			memset (vis, false, sizeof vis);
			memset (DIS, 0x3f, sizeof DIS);
			dis[i].push_back(0), djs(i);
			for (int j = 1; j <= n; j ++)
				dis[i].push_back(DIS[j]);
		}
		if (k == 2) {
			LL mi = INT_MAX;
			for (int i = 1; i < n; i ++)
				for (int j = i + 1; j <= n; j ++) {
					LL mx = 0;
					for (int p = 1; p <= n; p ++)
						mx = max(mx, (dis[i][p] == MOD ? 0:dis[i][p]));
					for (int p = 1; p <= n; p++)
						mx = max(mx, (dis[j][p] == MOD ? 0:dis[j][p]));
					mi = min(mi, mx);
				}
			cout << mi <<'\n';
		} else {
			
		}
	}
	return 0;
}
