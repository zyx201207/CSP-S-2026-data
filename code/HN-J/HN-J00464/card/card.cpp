#include <bits/stdc++.h>
using namespace std;

// RP++
// AC AC AC
// 图灵老祖助我一臂之力
// 图灵保佑 
// 
// 好无聊 (11:11) 
// dayz的time表太牢了 
// dayz class 850 的 ywb 和 js 是 (char)70 (char)101 (char)109 (char)98 (char)97 (char)121.

const int N = 5*1e5+5;
const int M = 3*1e5+5;

int n, m, a[N], ans[M], endat[M];
bool have[M];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		endat[a[i]] = i;
	}
	
	for (int i=1; i<=n; i++) {
		for (int j=i; j<=n; ) {
			if (j != endat[a[j]]) {
				j = endat[a[j]];
			}
			ans[a[j++]]++;
		}
	}
	
	for (int i=1; i<=m; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";

	return 0;
}

