#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5, MAXM = 3e5 + 5;
int n, m;
int a[MAXN], ans[MAXM];
void init(int x) {
	vector < int > sum(n + 1, 0);
	for(int i = x; i <= n; i++) {
		sum[a[i]]++;
	}
	for(; x <= n; x++) {
		int t = x;
		ans[a[x]]++;
		while(sum[a[t]] > 1) {
			x++;
			sum[a[t]] -= (a[x] == a[t]);
		}
	}
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		init(i);
	}
	for(int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}
// 暴力，不想想正解了，前面T2莫名其妙调了好久没时间了 
// 只剩10min，只花5min写出更优解 
