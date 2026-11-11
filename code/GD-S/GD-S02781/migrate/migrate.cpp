#include<bits/stdc++.h>
using namespace std;
int n, d;
int ans = 0;
int prin;
int pos[2000005];
bool vis[2000005];
int bfs(int x, int y) {
	queue<int> q;
	while(!q.empty()) q.pop();
	q.push(x);
	while(!q.empty()) {
		int f = q.front();
		q.pop();
		for(int i = f + 1; i <= y; i++) {
			if(pos[i] - pos[f] <= d && !vis[i]) {
				q.push(i);
				cout << i << '\n';
				if(i != y) vis[i] = true;
			} else break;
		}
	}

	int ans = 0;
	while(!q.empty()) {
		int f = q.front();
		q.pop();
		if(f == y) ans++;
	}
	return ans;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	int c, t;
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> pos[i];
		for(int i = 1; i <= n; i++) {
			for(int j = i + 3; j <= n; j++) {
				cout << i << ' ' << j << '\n';
				if(bfs(i, j) == 2) prin++;
			}
		}
	}
	cout << prin;
	return 0;
}
