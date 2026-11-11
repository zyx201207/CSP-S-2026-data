#include <iostream>
#include <algorithm>
using namespace std;

const int Len = 2e5 + 5;
int a[Len], vis[Len], dp[2][Len];
int n, m;
int ans;

void dfs(int cnt, int sum[], int num)
{
//	cout << "dfs(" << cnt << "," << sum[cnt-1] << ")\n";
	if (cnt >= m) {
		int maxn = sum[0];
//		cout << sum[0] << " ";
		for (int i=1;i<cnt;i++) {
//			cout << sum[i] << " ";
			maxn &= sum[i];
		}
//		cout << "\n";
		ans = max(ans, maxn);
		return;
	}
	for (int i=num;i<=n;i++) {
		if (vis[i] == 1) continue;
		vis[i] = 1;
		sum[cnt] = a[i];
		dfs(cnt+1, sum, num+1);
		vis[i] = 0;
	} 
}

bool cmp(int a, int b) {
	return a > b;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
	}
	
	sort(a+1, a+n+1);
	if (n <= 20000) {
		ans = -1;
		int t[25] = {};
		dfs(0, t, 1);
		
	}
	cout << ans << "\n";
	return 0;
}
