#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5, M = 32;
bool c[N][M];
long long a[N], b[N];
vector <int> ch;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	b[0] = 2147483647LL;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
		int cur = 0;
		while (a[i]) {
			c[i][cur++] = a[i] % 2;
			a[i] /= 2;
		}
	}
	for (int i = 1; i <= n; i++)
		ch.push_back(i);
	for (int i = M - 1; i >= 0; i--) {
		int cnt = 0;
		for (int p : ch)
			cnt += c[p][i];
		if (cnt >= m)
			for (int &p : ch)
				if (!c[p][i])
					p = 0;
	}
	long long ans = 2147483647LL;
	for (int p : ch)
		ans &= b[p];
	cout << ans << '\n';
	return 0;
}
