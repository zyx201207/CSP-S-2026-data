#include <bits/stdc++.h>

using namespace std;

using ll = long long; using ull = unsigned long long;
#define REP(i, l, r) for(int i = (l); i <= (r); ++i)
#define PER(i, r, l) for(int i = (r); i >= (l); --i)

bool mST;

namespace Main {

	const int N  = 1e6 + 5;
	int n, K;
	// int f[N][3][2];
	// 点-边 = 2, choose?
	vector<int> G[N];
	// void dfs(int u, int prt) {
	// 	for(int &v: G[u]) {
	// 		if(v != prt) continue;
	// 		dfs(v, u);
	// 		for(int j = 0; j <= 2; j++) REP(p,0,1){
	// 			REP(k, 0, 2) REP(q, 0, 1) {
	// 				int z=j+k+q-(p&&q);
	// 				if(z > 2) continue;
	// 				f[u][z][p]=min(f[u][z][p],max(f[u][j][p],f[v][k][q]));
	// 			}
	// 		}
	// 	}
	// }
	// bool chk(int mid) {
		
	// }
	int S,Z;
	void dfs(int u, int prt, int d) {
		if(S>>(u-1)&1) Z= min(Z,d);
		for(int &v: G[u]) {
			if(v==prt)continue;
			dfs(v,u,d+1);
		}
	}
	pair<int,int> e[N];
	void Solve() {
		cin >> n >> K;
		REP(i, 1, n - 1) {
			int u, v; cin >> u >> v;
			G[u].push_back(v), G[v].push_back(u);
			e[i] = {u, v};
		}
		int ans=  1e9;
		REP(s, 0, (1 << n) - 1) {
			if(__builtin_popcount(s) != K) continue;
			int res = 0;
			S = s;
			REP(i, 0, n - 1) Z = 1e9, dfs(i + 1, 0, 0), res=max(res, Z);
			int G = 0;
			REP(i, 0, n - 1) {
				G += (s >> i & 1);
			}
			REP(i, 1, n - 1)if((s >> (e[i].first - 1) & 1) && (s >> (e[i].second - 1) & 1)) G--;
			if(G <= 2)
				ans = min(ans, res);
		}
		// int l = 0, r = n, ans = n + 1; while(l <= r) {
		// 	int mid = (l + r) >> 1;
		// 	if(chk(mid)) r = mid - 1, ans = mid;
		// 	else l = mid + 1;
		// }
		cout << ans << '\n';

		REP(i, 1, n) G[i].clear();
	}

	int main() {
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		int cid, cases;
		cin >> cid >> cases;
		while(cases--) Solve();
		return 0; 
	}
}

bool mED;

int main() {
#ifndef Ace
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
//	freopen("hub.err", "w", stderr);
#endif
	Main::main();
	
	cerr << fixed << setprecision(3) << "Time:" << 1. * clock() / CLOCKS_PER_SEC << "s" << '\n';
	cerr << "static Memory: " << abs(&mST - &mED) / 1048576. << "mb" << '\n'; 
	return 0;
} 
/*
3s 1024M
*/