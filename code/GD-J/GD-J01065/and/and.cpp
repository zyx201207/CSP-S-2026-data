#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define endl '\n'

using namespace std;

const int N = 2e5 + 5;
int n, m, a[N];
//int bit[35][N];
//struct Sum {
//	int x, id;
//} sum[35];
//vector<int> im;

bool cmp(int x, int y) {
	return x > y;
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
//	for (int i = 1; i <= 30; i++) sum[i] = {0, i};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
//		int x = a[i], k = 0;
//		while (x) {
//			bit[++k][i] = x % 2;
//			x /= 2;
//		}
//		for (int j = 30; j >= 1; j--) {
//			sum[j].x += bit[j][i];
//		}
	}
//	sort(sum + 1, sum + 30, [](Sum x, Sum y) {
//		if (x.x != y.x) return x.x > y.x;
//		return x.id < y.id;
//	});
//	for (int i = 1; i <= 30; i++) im.push_back(sum[i].id);
	
	sort(a + 1, a + 1 + n, cmp);

	int ans = a[1];
	for (int i = 2; i <= m; i++) ans = ans & a[i];
	cout << ans << endl;
	return 0;
}
