#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e5 + 10;
int n, m;
int a[MAXN];
int s[MAXN];
bool check(int x, int qwq) {
	int awa = s[qwq] - s[x - 1];
	int len = qwq - x + 1;
	int dj = a[qwq] * len - awa;
//	cout << x << ' ' << qwq << ' ' << awa << ' ' << len << ' ' << dj << '\n';
	return dj <= m;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid, i)) r = mid - 1;
			else l = mid + 1;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
} 
/*
显然最后合成的肯定是初始的一个值，并且参与合成的这些数，一定是从小到大排序后的一个区间 

然后考虑枚举这个区间的右端点，然后二分即可 
*/
