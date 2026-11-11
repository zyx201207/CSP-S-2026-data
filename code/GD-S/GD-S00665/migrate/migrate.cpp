#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 5010

int c, t, n, d;
int x[N];
vector<int> e[N];
int dis[N];
int num[N];
queue<int> q;
void bfs(int s) {
	fill(dis + 1, dis + n + 1, 1e15);
	fill(num + 1, num + n + 1, 0);
	dis[s] = 0;
	num[s] = 1;
	q.push(s);
	while(q.size() != 0) {
		int h = q.front();
		q.pop();
		for(auto i:e[h]) {
			if(dis[i] == dis[h] + 1) {
				num[i] += num[h];
			} else if(dis[i] > dis[h] + 1) {
				dis[i] = dis[h] + 1;
				num[i] = num[h];
				q.push(i);
			}
		}
	}
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1;i <= n;i++) {
			cin >> x[i];
		}
		for(int i = 1;i <= n;i++) {
			e[i].clear();
		}
		for(int i = 1;i <= n;i++) {
			for(int j = i + 1;j <= n;j++) {
				if(abs(x[i] - x[j]) <= d) {
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
		
		int cnt = 0;
		for(int i = 1;i <= n;i++) {
			bfs(i);
			for(int j = i + 1;j <= n;j++) {
				//cout << i << "->" << j << " " << num[j] << "\n";
				if(num[j] == 2) {
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
} 
