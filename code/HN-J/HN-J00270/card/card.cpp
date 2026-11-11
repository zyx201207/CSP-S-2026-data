#include <bits/stdc++.h>
using namespace std;
 
int a[500001];

// dp[i]:第i位的被杀的最大次数 
int dp[500001];
// 每个数字上一次出现的位置，0表示没有或被杀 
int lastAppear[300001];

int ans[300001];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	bool ok = true;
	for (int i = 2; i <= n; i++) if (a[i] < a[i-1]) {
		ok = false;
		break;
	}
	
	if (ok) {
		for (int i = 1; i <= n; i++) ans[a[i]] = i;
	} else {	// 乱做的望CCF水数据给点分 
		for (int i = 1; i <= n; i++) {
		dp[i] = 0;
		
		if (lastAppear[a[i]]) for (int j = lastAppear[a[i]]+1; j < i; j++) {
			dp[j] = max(dp[j], lastAppear[a[i]]);
			lastAppear[j] = 0;
		}
		lastAppear[a[i]] = i;
	}
	
	for (int i = 1; i <= n; i++) ans[a[i]] = max(ans[a[i]], i - dp[i]);
	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
	}
	
	return 0; 
}

/*   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
 *   CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分    CCF给点分 
*/
