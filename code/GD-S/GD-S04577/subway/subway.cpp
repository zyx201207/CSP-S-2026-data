#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5;
int c, n, m, d, qq;
int w[N], t[N][25], k[510], mp[510][510];
int dp[510][510];
vector<int> num[N];
queue<int> q;
void dj(int i) {
	int minn = 1e15;
	q.push(i);
	bool vis[510];
	for(int k = 0;k <= 501; k ++) vis[k] = 0;
	vis[i] = 1;
	while(!q.empty()) {
		minn = 1e15;
		int idd = 0;
		int id = q.front(); q.pop();
		vis[id] = 1;
		for(int j = 1;j <= n; j ++) {
			if(mp[id][j] == 0 || vis[j]) continue;
			dp[i][j] = min(dp[i][j], dp[i][id] + mp[id][j]);
			if(dp[i][j] < minn) idd = j;
		}
		if(idd != 0) q.push(idd);
	}
	return ;
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d , &qq);
    for(int i = 1;i <= m; i ++) {
    	scanf("%d", &w[i]);
	} 
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j <= n;j ++) {
			if(i != j) {
				dp[i][j] = 1e15;
				mp[i][j] = 1e15;
			}
		}
	}
	for(int i = 1;i <= n;i ++) {
		cin >> k[i];
		for(int j = 1;j <= k[i];j ++) {
			int a, tt;
			cin >> a >> tt;
			t[a][num[a].size()] = tt;
			num[a].push_back(i);
		}
	}
	for(int kk = 1; kk <= m; kk ++) {
		if(num[kk].size() == 1) continue;
		for(int i = 0;i < num[kk].size(); i ++) {
			for(int j = i + 1;j < num[kk].size(); j ++) {
				int ii = num[kk][i], jj = num[kk][j], ht = t[kk][i] + t[kk][j];
				mp[ii][jj] = min(mp[ii][jj], ht);
				mp[jj][ii] = min(mp[jj][ii], ht);
			}
		}
	}
	for(int i = 1;i <= n; i ++) dj(i);
	while(qq --) {
		int minn = 1e15;
		int x, y;
		cin >> x >> y;
		for(int i = 0; i < num[x].size(); i ++) {
			for(int j = 0; j < num[y].size(); j ++) {
				minn = min(minn, dp[num[x][i]][num[y][j]] + w[x] + w[y] + t[x][i] + t[y][j]);
			}
		}
		printf("%d\n", minn);
	}
	return 0;
}
