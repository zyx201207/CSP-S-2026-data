#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 7, INF = 1e17;
int c, T, n, k, dis[N];
vector<int> s[N];
bool f[N], flag[N];

void dfs(int x){
	if(!f[x] || flag[x]) return;
	flag[x] = 1;
	for(int i : s[x]) dfs(i);
}

bool check1(){
	for(int i = 1; i <= n; i++) flag[i] = 0;
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(f[i] && !flag[i]) {dfs(i); ++cnt;}
	}
	return cnt <= 2;
}

int check2(){
	for(int i = 1; i <= n; i++) dis[i] = -1;
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(f[i]) q.push(i), dis[i] = 0;
	}
	int mx = 0;
	while(!q.empty()){
		int x = q.front(); q.pop();
		mx = max(mx, dis[x]);
		for(int i : s[x]){
			if(dis[i] == -1){
				dis[i] = dis[x] + 1, q.push(i);
			}
		}
	}
	return mx;
}

void S(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++) s[i].clear();
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		s[u].push_back(v), s[v].push_back(u);
	}
	if(n <= 10){
		int ans = INF;
		for(int i = 0; i < (1 << n); i++){
			int cnt = 0;
			for(int j = 0; j < n; j++){
				f[j + 1] = i >> j & 1;
				cnt += (i >> j & 1);
			}
			if(cnt == k && check1()) ans = min(ans, check2());
		}
		cout << ans << '\n';
	}
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T; while(T--) S();
	return 0;
}
