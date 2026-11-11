

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 4010;

int c;
int t;
int n;
int k;
vector<int> tree[N];
int dad[N];
int dep[N];
int sub_size[N];
int cal[N];
int cal_cc[N][N];

bool grand[N][N];
int dp[N][N];
int res;

void dfs (int u, int fa) {
	dad[u] = fa;
	dep[u] = dep[fa] + 1;
	sub_size[u] = 1;
	memset (cal_cc[u], 0, sizeof (cal_cc[u]));
	cal[u] = 1;
	memset (grand[u], 0, sizeof (grand[u]));
	grand[u][u] = true;
	
	for (auto v : tree[u]) {
		if (v == fa) {
			continue;
		}
		dfs (v, u);
		sub_size[u] += sub_size[v];
		cal[u] = max (cal[u], cal[v] + 1);
		for (int i = 1; i <= n; i++) {
			cal_cc[u][i] += cal_cc[v][i];
		}
		for (int i = 1; i <= n; i++) {
			if (grand[v][i]) {
				grand[u][i] = true;
			}
		}
	}
	cal_cc[u][cal[u]]++;
	
	int sz = sub_size[u];
	int now_cal = 1;
	int now_cc = 0;
	now_cc = cal_cc[u][now_cal];
	dp[u][sz] = dep[u] - 1;
	for (int i = sz - 1; i >= 0; i--) {
		now_cc--;
		dp[u][i] = max (now_cal, dep[u] - 1);
		if (!now_cc) {
			now_cal++;
			now_cc = cal_cc[u][now_cal];
		}
	}
}

int main () {
	
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	
	scanf ("%d%d", &c, &t);
	for (int index = 1; index <= t; index++) {
		scanf ("%d%d", &n, &k);
		int u, v;
		for (int i = 1; i <= n; i++) {
			tree[i].clear();
		}
		for (int i = 1; i < n; i++) {
			scanf ("%d%d", &u, &v);
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		
		dfs (1, 0);
//		for (int i = 1; i <= n; i++) {
//			cout << i << endl;
//			for (int j = 1; j <= n; j++) {
//				cout << dp[i][j] << ' ';
//			}
//			cout << endl;
//		}

		res = n;
		for (int u = 1; u <= n; u++) {
//			cout << u << ' ' << sub_size[u] << endl;
			if (sub_size[u] >= k) {	
				res = min (res, dp[u][k]);
			}
			
			for (int v = u + 1; v <= n; v++) {
				if (!grand[u][v] && !grand[v][u]) {
					for (int i = 0; i <= k; i++) {
						res = min (res, max (dp[u][i], dp[v][k - i]));
					}
				}
			}
			
			for (auto v : tree[u]) {
				if (v == dad[u]) {
					continue;
				}
					
				for (int uu = 1; uu <= n; uu++) {
					if (!grand[u][uu]) {
						continue;
					}
					if (grand[v][uu]) {
						continue;
					}
					
					for (int i = 0; i + 1 <= k; i++) {
						res = min (res, max (dp[uu][i], dp[v][k - i - 1]));
					}
				}
			}
		}
		
		cout << res << endl;
	}
	
	return 0;
}