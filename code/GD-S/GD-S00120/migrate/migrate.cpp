#include <bits/stdc++.h>
#include <assert.h>
int c, T = 1;
namespace cjdst{
	typedef long long ll;
	typedef unsigned long long ull;
	typedef std::pair <int, int> pii;
	typedef std::pair <ll, ll> pll;
	
	void init(){
		std::ios::sync_with_stdio(0);
		std::cin.tie(0), std::cout.tie(0);
	}
	
	/*
	哇，n^2有高达50pts 
	往返肯定是不优的，所以考虑一直往右跳 
	如果说一个点能被三个以上的到达，那这个点一定不能被选 
	*/
	
	const ll N = 5000, N2 = 2000000, mod0 = 1e9 + 9, mod1 = 676766767, mod2 = 6767998244853ll;
	ll a[N2 + 5];
	ll dp[N + 5][3], pre[N + 5][3];
	int dis[N + 5];
	ll n, m;
	
	void solve_bf(){
		std::cin >> n >> m;
		for(int i = 1; i <= n; i++){
			std::cin >> a[i];
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			/*// sum n <= 5000，memset 放心用 
			memset(dp, 0, sizeof(dp));
			memset(pre, 0, sizeof(pre));
			memset(dis, 0, sizeof(dis));*/
			for(int j = 0; j <= n; j++){
				for(int k = 0; k < 3; k++){
					dp[j][k] = pre[j][k] = 0;
				}
				dis[j] = 0;
			}
			int l = i, l2 = i;
			for(int j = 0; j < 3; j++){
				dp[i][j] = pre[i][j] = 1;
			}
			for(int j = i + 1; j <= n; j++){
				while(l <= j && a[j] - a[l] > m) l++;
				dis[j] = dis[l] + 1;
				while(l2 <= j && dis[j] != dis[l2]) l2++;
				dp[j][0] = (pre[l2 - 1][0] - pre[l - 1][0] + mod0) % mod0;
				dp[j][1] = (pre[l2 - 1][1] - pre[l - 1][1] + mod1) % mod1;
				dp[j][2] = (pre[l2 - 1][2] - pre[l - 1][2] + mod2) % mod2;
				pre[j][0] = (pre[j - 1][0] + dp[j][0]) % mod0;
				pre[j][1] = (pre[j - 1][1] + dp[j][1]) % mod1;
				pre[j][2] = (pre[j - 1][2] + dp[j][2]) % mod2;
				// std::cout << i << ' ' << j << ' ' << dp[j][0] << ' ' << dis[j] << '\n';
				if(dp[j][0] == 2 && dp[j][1] == 2 && dp[j][2] == 2){
					// std::cout << i << ' ' << j << '\n';
					ans++;
				}
			}
		}
		std::cout << ans << '\n';
	}
	
	void solve_A(){
		std::cin >> n >> m;
		for(int i = 1; i <= n; i++){
			std::cin >> a[i];
		}
		if(n == 1){
			std::cout << "0\n";
			return;
		}
		ll dis = m / (a[2] - a[1]);
		if(dis <= 1) std::cout << "0\n";
		else std::cout << std::max(0ll, n - dis * 2 + 1) << '\n';
	}
	
	ll nxt[N2];
	
	void solve_B(){
		std::cin >> n >> m;
		for(int i = 1; i <= n; i++){
			std::cin >> a[i];
		}
		int l = 0, r = 0;
		nxt[0] = 1;
		for(int i = 1; i <= n; i++){
			nxt[i] = nxt[i - 1];
			while(nxt[i] <= n && a[nxt[i]] - a[i] <= m) nxt[i]++;
			if(a[i] - a[1] <= m && a[n] - a[i] <= m){
				r = i;
				if(!l) l = i;
			}
		}
		for(int i = 1; i <= n; i++){
			nxt[i]--;
			std::cout << nxt[i] << ' ';
		}
		if(r - l + 1 > 2 || !l){
			std::cout << "0\n";
			return;
		}
		ll ans = 0;
		for(int i = 1; i < l; i++){
			std::vector <ll> v;
			for(int j = std::max(l - 2, i); j <= std::min(r + 2ll, n); j++){
				v.push_back(nxt[j] - 1);
			}
			if(v.size() < 2) continue;
			std::cout << i << ": [" << v[1] << ", " << v[2] - 1 << "]\n"; 
			ans += (v[2] - v[1]);
		}
		std::cout << ans << '\n';
	}
	
	void solve(){
		if(c <= 10) solve_bf();
		else if(c == 11 || c == 12) solve_A();
		else if(c == 13 || c == 14) solve_B();
		else std::cout << "0\n";
	}
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cjdst::init();
	std::cin >> c >> T;
	for(int _ = 1; _ <= T; _++){
		cjdst::solve();
	} 
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
