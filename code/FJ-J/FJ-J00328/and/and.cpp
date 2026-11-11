#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 2e5 + 5;
int a[MAXN];
bool cmp(int x, int y) { return x > y; }
int main() {
	freopen("and.in", "r", stdin); freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	int y = 2147483647;
	for (int i = 1; i <= m; i ++) y &= a[i];
	cout << y;
	return 0;
}

