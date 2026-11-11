#include<bits/stdc++.h>
using namespace std;
namespace cqsunny{
	const int N = 1e6 + 10; 
	int c, T, n, k, ans;
	vector<int> v[N];
	bool fl[N], vs[N];
	int d[N];
	void dfs2(int x, int fa){
		vs[x] = 1;
		for(auto i : v[x]){
			if(i == fa || !fl[i] || vs[i]) continue;
			dfs2(i, x); 
		} 
	}
	void dfs3(int x, int fa, int ds){
		d[x] = min(d[x], ds);
		for(auto i : v[x]){
			if(i == fa) continue;
			dfs3(i, x, ds + 1);
		}
	}
	void dfs(int x, int y){
		if(x > n){
			if(y) return;
			for(int i = 1; i <= n; ++ i) vs[i] = 0;
			int s = 0;
			for(int i = 1; i <= n; ++ i){
				if(fl[i] && !vs[i]){
					dfs2(i, 0);
					++ s;
				}
			}
			if(s > 2) return;
			for(int i = 1; i <= n; ++ i) d[i] = n;
			for(int i = 1; i <= n; ++ i){
				if(fl[i]){
					dfs3(i, 0, 0);
				}
			}
			int ss = 0;
			for(int i = 1; i <= n; ++ i) ss = max(ss, d[i]);
			ans = min(ans, ss);
			return;
		}
		if(y){
			fl[x] = 1;
			dfs(x + 1, y - 1);
			fl[x] = 0;
		}
		dfs(x + 1, y);
	}
	bool check(){
		if(!(n & 1)) return 0;
		int t = n >> 1;
		for(int i = 1; i <= t; ++ i){
			int tt = v[i].size();
//			printf("%d %d %d %d\n", i, tt, v[i][0], v[i][1]);
			if(i == 1){
				if(tt != 2) return 0;
				if(v[i][0] != i + 1) return 0;
				if(v[i][1] != i + t + 1) return 0;
			}
			else{
				if(tt != 3) return 0;
				if(v[i][1] != i + 1) return 0;
				if(v[i][2] != i + t + 1) return 0;
			}
		}
		return 1;
	}
	bool check(int x){
		int t = (n + 1) >> 1;
		int r1 = (k + 1) >> 1, r2 = k - r1;
		int tt = x + r1 - 1 + 2 * x + r2 - 1 + x;
		if(tt >= t) return 1;
		return 0;
	}
	int main(){
	//	freopen("hub5.in", "r", stdin);
		freopen("hub.in", "r", stdin);
		freopen("hub.out", "w", stdout);
		scanf("%d %d", &c, &T);
		while(T --){
			scanf("%d %d", &n, &k);
			for(int i = 1; i <= n; ++ i) v[i].clear();
			for(int i = 1; i < n; ++ i){
				int x, y;
				scanf("%d %d", &x, &y);
				v[x].emplace_back(y);
				v[y].emplace_back(x);
			}
			if(n <= 10){
				ans = n;
				dfs(1, k);
				printf("%d\n", ans);
				continue;
			}
			if(n == k){
				printf("0\n");
				continue;
			} 
			if(check()){
				int l = 1, r = n, ans = n;
				while(l <= r){
					int mid = (l + r) >> 1;
					if(check(mid)){
						ans = mid;
						r = mid - 1;
					}
					else{
						l = mid + 1;
					}
				}
				printf("%d\n", ans);
				continue;
			}
		}
		return 0;
	}
}
int main(){
	return cqsunny::main();
}
