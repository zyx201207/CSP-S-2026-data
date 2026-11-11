#include <bits/stdc++.h>

using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e6 + 10;
long long x[N];
int f[N], c[N];

long long get(int x) {
	if (x < 4) return 0LL;
	return 1LL * (x - 3) * (x / 2) / 2;
}

void solve() {
	int n;
	long long d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	x[n + 1] = INF;
	for (int i = 1; i <= n; i++) {
		f[i] = upper_bound(f + 1, f + n + 1, x[i] + d) - f - i;
		cout << f[i] << ' ';
	} cout << '\n';
	return ;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	memset(f, 0x3f, sizeof(f));
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, T;
	cin >> c >> T;
	while (T--)
		solve();
	return 0;
}
