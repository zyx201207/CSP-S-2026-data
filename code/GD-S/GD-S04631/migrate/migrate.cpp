#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e6 + 5, MAX = 1e17 + 5;

struct node{
	int di, bh;
	bool operator <(const node &x) const{
		return x.di < di;
	}
};

int c, t, n, d, a[MAXN], dis[MAXN], cnt[MAXN], ans;
vector<int>edge[MAXN];
priority_queue<node>q;
bool vis[MAXN];

void dj(int st) {
	for (int i = 1; i <= n; i++) {
		dis[i] = MAX;
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) {
		cnt[i] = 1;
	}
	
	dis[st] = 0;
	q.push((node){0, st});
	
	while(!q.empty()) {
		int u = q.top().bh;
		q.pop();
		
		//cout << u << " " << dis[u] << endl;
		
		//cout << edge[u].size() << endl;
		
		for (int v : edge[u]) {
			//cout << u << " " << v << "asd" << endl;
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				cnt[v] = cnt[u];
				q.push((node){dis[v], v});
			}
			else if (dis[v] == dis[u] + 1) {
				cnt[v]++;
				//q.push((node){v, dis[v]});
			}
		}
	}
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> t;
	while(t--) {
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			edge[i].clear();
		}
		
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				//if (i == j) continue;
				int o = abs(a[i] - a[j]);
				if (o <= d) {
					//cout << i << " " << j << endl;
					edge[i].push_back(j);
					edge[j].push_back(i);
				}
			}
		}
		
		for (int i = 1; i <= n; i++) {
			dj(i);
			for (int j = i + 1; j <= n; j++) {
				//cout << i << " " << j << " " << cnt[j] << endl;
				if (cnt[j] == 2) {
					ans++;
				}
			}
		}
		
		cout << ans << "\n";
	}
}
