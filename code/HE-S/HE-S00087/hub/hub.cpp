#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int tc, t, n, f[N], k, dist[N];
vector<int> e[N];
int findset(int x){
	return f[x] == x ? x : f[x] = findset(f[x]);
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> tc >> t;
	for(; t--; ){
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
			e[i].clear();
		for(int i= 1; i < n; i++){
			int x, y;
			cin >> x >> y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		int ans = n;
		for(int mask = 0; mask < (1 << n); mask++){
			if(__builtin_popcount(mask) != k) continue;
			int cnt = k;
			for(int i = 1; i <= n; i++)
				f[i] = i;
			for(int i = 1; i <= n; i++){
				if(mask & (1 << (i - 1))){
					for(auto j : e[i])
						if(mask & (1 << (j - 1))){
							int sx = findset(i), sy = findset(j);
							if(sx == sy) continue;
							--cnt;
							f[sx] = sy;
						}
				}
			}
			if(cnt > 2) continue;
			queue<int> q;
			for(int i = 1; i <= n; i++){
				if(mask & (1 << (i - 1)))
					dist[i] = 0, q.push(i);
				else
					dist[i] = -1;
			}
			int val = 0;
			while(!q.empty()){
				int x = q.front();
				q.pop();
				for(auto y : e[x])
					if(dist[y] == -1){
						dist[y] = dist[x] + 1;
						q.push(y);
						val = max(val, dist[y]);
					}
			}
			ans = min(ans, val);
		}
		cout << ans << '\n';
	}
	return 0;
} 
