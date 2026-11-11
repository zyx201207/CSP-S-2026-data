#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
int nums[1000000];
int ans = -1;

void dfs(int st, int sum, int cnt){
	if (st > n || cnt >= m){
		if (cnt == m) ans = max(ans, sum);
		return;
	}
//	if (n - st < m - cnt) return;
	dfs(st + 1, sum, cnt);
	if (sum == -1) sum = nums[st];
	dfs(st + 1, sum & nums[st], cnt + 1);
}

signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> nums[i];
	dfs(1, -1, 0);
	cout << ans;
}
