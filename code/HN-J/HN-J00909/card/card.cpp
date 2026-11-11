#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define st first
#define nd second
using namespace std;
const int N = 5e5 + 7;
int n, m, a[N], lst[N], f[N], ans[N];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = n; i >= 1; i --)
		if (!lst[a[i]])
			lst[a[i]] = i;
	for (int i = 1; i <= n; i ++)
		f[i] ++, ans[a[i]] += f[i], f[lst[a[i]] + 1] += f[i];
	for (int i = 1; i <= m; i ++)
		cout << ans[i] << ' ';
	return 0;
}
/*
我差点没AKJ... 
呜啊嗯这个太容易被窥屏了吧
好恐怖感觉旁边的人在窥我屏，监考也在窥
监考是P话哥，虽然确实不是很难就是了 
*/
