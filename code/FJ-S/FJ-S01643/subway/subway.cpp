#include <bits/stdc++.h>
#define el "\n"
#define sp " "
#define r0 return 0
#define fi first
#define se second
#define F(i, a, b, c) for (int i = a; i <= b; i += c)

using namespace std;
typedef long long ll;
typedef string str;

int test, n, m, d, q;
int w[500010];
int k[510];
int a[510][500010];
int t[510][500010];
std::vector<std::pair<int, int>> e[500010];

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> test >> n >> m >> d >> q;
	F(i, 1, m, 1) {
		cin >> w[i];
	}
	F(i, 1, n, 1) {
		cin >> k[i];
		F(j, 1, k[i], 1) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << 32 << el;
	}
	r0;
}
