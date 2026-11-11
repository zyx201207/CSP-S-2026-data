#include<bits/stdc++.h>
using namespace std;
const int N = 90;
vector<int> vec[N];
bool duan[N], vis[N], vis2[N];
int ans, cnt;
void dfs(int s) {
	vis[s] = 1;
	for(auto v : vec[s]) {
		if(duan[v] && !vis[v]) {
			dfs(v);
		}
	}
	return;
}
void bfs(int s) {
	queue<pair<int, int> > q;
	q.push(make_pair(s, 0));
	while(!q.empty()) {
		int e = q.front().first;
		int w = q.front().second;
		cout << s << " " << e << " " << w << endl;
		q.pop();
		if(vis2[s]) continue;
		vis2[s]  = 1;
		for(auto v : vec[e]) {
			cout << 12121212;
			if(duan[v] && v != e) {
				q.push(make_pair(v, -1));
				cout << "12122"<<v << endl;
			} else if(v != e){
				cout << "1212" << v << " " << w + 1 << endl;
				q.push(make_pair(v, w + 1));
				ans = max(ans, w + 1);
			}
		}
	}
	return;
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int c, T; cin >> c >> T;
	while(T --) {
		ans = 0;
		int n, k; cin >> n >> k;
		for(int i = 1;i < n;i ++) {
			int u, v; cin >> u >> v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		if(n <= 10) {
			for(int i = 0;i < (1 << n);i ++) {
				memset(duan, 0, sizeof(duan));
				int ji = 0; cnt = 0;
				for(int j = 0;j < n;j ++) {
					if(i & (1 << j)) ji ++, duan[j + 1] = 1;
				}
				
				if(ji != k) continue;
				for(int i = 1;i <= n;i ++) {
					if(duan[i] && !vis[i]) {
						cnt ++;
						dfs(i);
					}
				}
				memset(vis, 0, sizeof(vis));
				if(cnt > 2) continue;
				
			
				
				for(int i = 1;i <= n;i ++) {
					if(!duan[i]) {
						bfs(i);
						break;
					}
				}
				
			}
			memset(vis2, 0, sizeof(vis2));
			cout << ans << endl;
			for(int i = 1;i < n;i ++) {
				vec[i].clear();
			}
		} else {
			int num = (n - 1) / 2;
			if(k >= num) {
				cout << 0 << endl;
				continue;
			} else {
				for(int i = 1;i * 2 <= k;i *= 2) {
					int kl = num;
					num = (num - 1) / 2;
					if(num*2 != kl) num ++;
				}
				cout << num + 1 << endl;
			}
		}
	}
	return 0;
}
