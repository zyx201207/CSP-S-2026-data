#include <bits/stdc++.h>
using namespace std;

struct node {
	long long s_cnt, s_num;
} dp[1010][20][20];
long long n, m, ans = -1000000000000000000, abc;
long long arr[500010];
map<long long, long long> mp;

void dfs(long long dep, long long cnt) {
	mp.clear();
	for(int i = 1; i <= n; i++) {
		mp[arr[i]]++;
		ans = max(ans, mp[arr[i]]);
	}
	if(dep > n) {
		return;
	}
	for(long long i = cnt; i >= 0; i--) {
		arr[dep] += i;
		dfs(dep + 1, cnt - i);
		arr[dep] -= i;
	}
	return;
}

void solve_dfs() {
	dfs(1, m);
	cout << ans << '\n';
	return;
}

void solve_dp() {
	for(long long cnt = 0; cnt <= m; cnt++) {
		for(int abc = 1; abc <= n; abc++) {
			dp[cnt][abc][abc] = {1, arr[abc]};
		}
	}
	for(long long cnt = 0; cnt <= m; cnt++) {
		for(int len = 2; len <= n; len++) {
			for(int l = 1; l <= n - len + 1; l++) {
				int r = l + len - 1;
				for(int pos = l; pos < r; pos++) {
					for(int num = 0; num <= cnt; num++) {
//						cout << "cnt = " << cnt << ", l = " << l << ", r = " << r << ", pos = " << pos << ", num = " << num << ':' << '\n';
//						cout << "dp[" << num << "][" << l << "][" << pos << "] = {" << dp[num][l][pos].s_cnt << "," << dp[num][l][pos].s_num << "}, ";
//						cout << "dp[" << cnt - num << "][" << pos + 1 << "][" << r << "] = {" << dp[cnt - pos][pos + 1][r].s_cnt << "," << dp[cnt - pos][pos + 1][r].s_num << "}, ";
//						cout << "dp[" << cnt << "][" << l << "][" << r << "] = {" << dp[cnt][l][r].s_cnt << "," << dp[cnt][l][r].s_num << '}' << '\n' << '\n';
						
						
						node nxt;
						if(dp[num][l][pos].s_num == dp[cnt - num][pos + 1][r].s_num) {
							nxt = {dp[num][l][pos].s_cnt + dp[cnt - num][pos + 1][r].s_cnt, dp[num][l][pos].s_num};
						}
						else {
							if(dp[num][l][pos].s_cnt > dp[cnt - num][pos + 1][r].s_cnt) {
								nxt = dp[num][l][pos];
							}
							else {
								nxt = dp[cnt - num][pos + 1][r];
							}
						}
						if(dp[cnt][l][r].s_cnt < nxt.s_cnt) {
							dp[cnt][l][r] = nxt;
						}
					}
				}
			}
		}
	}
	
//	for(int cnt = 0; cnt <= m; cnt++) {
//		cout << "cnt = " << cnt << ':' << '\n';
//		for(int i = 1; i <= n; i++) {
//			for(int j = 1; j <= n; j++) {
//				cout << '(' << dp[cnt][i][j].s_cnt << ',' << dp[cnt][i][j].s_num << ") ";
//			}
//			cout << '\n';
//		}
//		cout << '\n';
//	}
	
	cout << dp[m][1][n].s_cnt << '\n';
	return;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%lld %lld", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
	}
	solve_dfs();
//	solve_dp();
	return 0;
}
