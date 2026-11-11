#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
int n, K;
vector<int> V;

int get_(int x) {
	int res = 0;
	while (x >= 1) {
		x -= x & -x;
		res ++;
	}
	return res;
}

const int N = 3e5 + 10;
vector<int> G[N];
int mp[25][25];

bool jd() {
	int res = 0;
	for (int i : V) {
		for (int j : V) if (i != j && i < j) {
			if (mp[i][j] != 0) {
				res ++;
			}
		}
	}
	if (res < K - 2) {
		return 0;
	}
	return 1;
}

int dep[N], fa[N];

void dfs(int x, int p) {
	dep[x] = dep[p] + 1;
	fa[x] = p;
	for (int y : G[x]) if (y != p) {
		dfs(y, x);
	}
}

int dis(int x, int y) {
	int res = 0;
	while (x != y) {
		if (dep[x] < dep[y]) swap(x, y);
		x = fa[x];
		res ++;
	}
	return res;
}

int shu() {
	int res = 0;
	for (int i = 1; i <= n; i ++) {
		int tmp = n;
		for (int j : V) {
			tmp = min(tmp, dis(i, j));
		}
		res = max(res, tmp);
	}
	return res;
}

int dp[N][3], modep[N];
void dfsb(int x, int p) {
	dp[x][0] = dp[x][1] = dp[x][2] = n;
	modep[x] = 1;
	for (int y : G[x]) if (y != p) {
		dfsb(y, x);
		dp[x][2] = min(dp[x][2], max(1, dp[y][2]));
		
		dp[x][1] = min(dp[x][1], max(1, dp[y][1]));
	}
	if ((int)G[x].size() == 1) {
		dp[x][0] = 1;
		dp[x][1] = dp[x][2] = 0;
		modep[x] = 1;
	}
}

int main () {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int TC, T;
	cin >> TC >> T;
	while (T --) {
		cin >> n >> K;
		for (int i = 1; i <= n; i ++) G[i].clear();
		if (n <= 20) {
			
			memset(mp, 0, sizeof(mp));
			
			for (int i = 1; i < n; i ++) {
				int x, y;
				cin >> x >> y;
				G[x].push_back(y);
				G[y].push_back(x);
				mp[x][y] = mp[y][x] = 1;
			}
			
			dep[0] = 0;
			dfs(1, 0);
			
			int ans = n;
			for (int i = 0; i < (1 << n); i ++) if (get_(i) == K) {
				V.clear();
				for (int j = 0; j < n; j ++) if ((1 << j) & i) {
					V.push_back(j + 1);
				}
				if (!jd()) continue;
				ans = min(ans, shu());
//				if (ans == 1) {
//					cout << i << "\n";
//				}
			}
			cout << ans << "\n";
		}
		else if (K == 2) {
			for (int i = 1; i < n; i ++) {
				int x, y;
				cin >> x >> y;
				G[x].push_back(y);
				G[y].push_back(x);
			}
			dfsb(1, 0);
			cout << "1\n";
		}
		else {
			for (int i = 1; i < n; i ++) {
				int x, y;
				cin >> x >> y;
				G[x].push_back(y);
				G[y].push_back(x);
			}
			cout << "1\n";
		}
	}
	
	return 0;
}
