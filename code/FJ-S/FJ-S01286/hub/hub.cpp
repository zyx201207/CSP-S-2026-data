#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;

int n,k;
int c,T;
int f[MAXN];
int a[MAXN];
int dp[MAXN][MAXN];
int idx = 0;
int find(int x) {
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
} 
void uio(int x,int y) {
	int rx = find(x),ry = find(y);
	f[rx] = ry;
}
int ans = INT_MAX;
void dfs(int step,int sum) {
	if(step == n + 1) {
		int cnt = 0;
		map <int,vector<int>> mp;
		for(int i = 1;i <= idx;i++) {
			if(!mp.count(f[a[idx]])) {
				cnt++;
				mp[f[a[idx]]].push_back(a[idx]);
			}
		}
		if(cnt <= 2) {
			int maxn = INT_MIN;
			for(int i = 1;i < idx;i++) {
				for(int j = i + 1;j <= idx;j++) {
					maxn = max(maxn,dp[i][j]);
				}
			} ans = min(ans,maxn);
		} return;
	}
	if(sum < k) {
		a[++idx] = step;
		dfs(step + 1,sum + 1);
		a[idx] = 0;
		idx--;
	} dfs(step + 1,sum);
}

int main() {
	freopen("xxx.in","r",stdin);
	freopen("xxx.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> T;
	while(T--) {
		memset(dp,0x3f,sizeof dp);
		memset(a,0,sizeof a);
		idx = 0,ans = INT_MAX;
		cin >> n >> k;
		for(int i = 1;i <= n;i++) dp[i][i] = 0;
		for(int i = 1;i <= n;i++) f[i] = i;
		for(int i = 1;i <= n - 1;i++) {
			int u,v;
			cin >> u >> v;
			dp[u][v] = 1,dp[v][u] = 1;
			uio(u,v);
		}
		for(int k = 1;k <= n;k++) {
			for(int i = 1;i <= n;i++) {
				for(int j = 1;j <= n;j++) dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
			}
		} dfs(1,0);
		cout << 0 << '\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

