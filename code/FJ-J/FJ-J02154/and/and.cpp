#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, m, ans;
pair<int, int> cnt[35];
bool cmp(pair<int, int> x, pair<int, int> y) {
	if (x.first != y.first) return x.first > y.first;
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	for (int i = 0; i < 35; i++) cnt[i].second = 1 << i;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, j = 0;
		cin >> a;
		while(a) {
			if (a % 2) cnt[j].first++;
			j++;
			a /= 2;
		}
	}
	sort(cnt, cnt + 30, cmp);
	for (int i = 0; i < m; i++) ans += cnt[i].second;
	cout << ans;
	return 0;
}
