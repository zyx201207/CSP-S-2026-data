#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;
const int N = 2e6 + 10;
int c, t, n;
long long a[N], d;
vector<int> g[N];
int dis[N], mnd[N];

int bfs(int s){
//	cout << s << '\n';
	int res = 0;
	memset(dis, 0x3f, sizeof(dis));
	memset(mnd, 0, sizeof(dis));
	queue<PII> q;
	q.push({0, s});
//	dis[s] = 0;
	while (!q.empty()){
		PII u = q.front(); q.pop();
		if (u.first == dis[u.second]) mnd[u.second]++;
		else if (u.first < dis[u.second]){
			dis[u.second] = u.first;
			mnd[u.second] = 1;
		}else continue;
//		cout << u.second << " " << dis[u.second] << " " << mnd[u.second] << "\n"; 
		dis[u.second] = u.first;
		for (int v : g[u.second]){
			q.push({1 + u.first, v});
		}
	}
	for (int i=s+1; i<=n; i++){
		if (mnd[i] == 2) res++;
	}
	return res;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i=1; i<=n; i++){
			g[i].clear();
			cin >> a[i];
			for (int j=i-1; j>=1; j--){
				if (a[i] - a[j] <= d) g[j].push_back(i);
				else break;
			}
		}
		for (int i=1; i<=n; i++){
//			for (int v : g[i]) cout << i << "->" << v << '\n';
		}
		int ans = 0;
		for (int i=1; i<=n; i++){
			ans += bfs(i);
		}
		cout << ans << '\n';
	}
	return 0;
}
