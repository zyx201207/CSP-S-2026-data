#include <bits/stdc++.h>
using std::cin; using std::cout;
using std::min; using std::max;

const int N = 1e6 + 10;

int c, t;
int n, k;
std::vector< int > edge[N];

bool vis[N], vis2[N];
int dis[N];
int scc_cnt, cur;
int p[N];
int ans = 0x3f3f3f3f;

inline void dfs2(int u, int k) {
	
	bool flag = false;
	for (int i = 1; i <= k; ++ i) {
		if (u == p[i]) {
			flag = true;
			break;
		}
	}
	if (!flag) return ;
	
	if (vis[u]) return ;
	vis[u] = true;
	for (const auto& v : edge[u]) {
		dfs2(v, k);
	}
}

inline void dist(int now, int end, int num, bool& ok) {
	if (ok) return ;	
	
//	cout << "dis now : " << now << '\n';
	
	if (now == end) {
		
		cur = num;
		ok = true;
			
		return ;
	}
	
	if (!vis2[now]) {
		vis2[now] = true;
		for (const auto& v : edge[now]) {
			dist(v, end, num + 1, ok);
		}
	}
	
	return ;
}

inline void dfs1(int k, int step) {
	if (step > k) {
		
//		for (int i = 1; i <= k; ++ i) {
//			cout << p[i] << ' ';
//		}
//		cout << '\n';
		
		scc_cnt = 0; 	
		for (int i = 1; i <= n; ++ i) vis[i] = vis2[i] = false;
		for (int i = 1; i <= n; ++ i) dis[i] = 0;
		
		for (int i = 1; i <= k; ++ i) {
			if (!vis[p[i]]) {
				++ scc_cnt;
				dfs2(p[i], k);
			}
		}
		
//		cout << "scc_cnt : " << scc_cnt << '\n';
		if (scc_cnt > 2) return ;
		
		for (int i = 1; i <= n; ++ i) {
			int minn = 0x3f3f3f3f;
			bool flag = false;
			for (int j = 1; j <= k; ++ j) {
				if (i == p[j]) {
					flag = true;
					break;
				}
			}
			if (flag == true) {
				dis[i] = 0x3f3f3f3f;
				continue;
			}
			
			for (int j = 1; j <= k; ++ j) {
				
//				cout << "u : " << i << " v : " << p[j] << '\n';
				
				bool ok = false;
				cur = 0x3f3f3f3f;
				for (int i = 1; i <= n; ++ i) vis2[i] = false;
				dist(i, p[j], 0, ok); 
//				cout << "dis :" << cur << '\n';
				minn = std::min(minn, cur);
			}
				
			dis[i] = minn;
		}
//		cout << "dis : " << ' ';
//		for (int i = 1; i <= n; ++ i) cout << dis[i] << ' ';
//		cout << '\n';
		
		int r = 0;
		for (int i = 1; i <= n; ++ i) {
			if (dis[i] == 0x3f3f3f3f) continue;
			r = max(r, dis[i]);	
		}
		
		ans = std::min(ans, r);
		
		return ;
		
	}
	
	for (int i = p[step - 1] + 1; i <= n; ++ i) {
		p[step] = i;
		dfs1(k, step + 1);
	}
}

int main()
{
	
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	
	cin >> c >> t;
	
	while (t --) {
		ans = 0x3f3f3f3f;
		
		cin >> n >> k;
		for (int i = 1; i <= n; ++ i) edge[i].clear();
		for (int i = 1; i < n; ++ i) {
			int u, v; cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		
//		cout << "##" << '\n';
		
		for (int i = 1; i <= n; ++ i) p[i] = 0;
		dfs1(k, 1); 
		
		cout << ans << '\n';
		
	}
	
	return 0;
	
} 

/*
0 2

5 2
1 2
2 3
3 4
4 5

10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10


*/
