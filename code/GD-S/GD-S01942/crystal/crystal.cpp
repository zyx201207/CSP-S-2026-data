#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5010;
int n, cnt = -1;
int a1, a2;
ll m, a[N], f[N][N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n - 1; i++) {
		f[i][i + 1] = a[i + 1] - a[i];
	}
	for (int i = 3; i <= n; i++) {
		for (int st = 1; st < n; st++) {
			int ed = st + i - 1;
			if (ed > n) continue;
			f[st][ed] = f[st][ed - 1] + abs(a[ed] - a[ed - 1]) * (ed - st);
			if (f[st][ed] <= m) {
				cnt = max(cnt, ed - st + 1);
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}

