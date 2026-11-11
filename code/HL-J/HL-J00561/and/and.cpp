#include <bits/stdc++.h>

using namespace std;

int cntbit(int x) {
	int cnt = 0;
	while (x) {
		x >>= 1;
		cnt++;
	}
	return cnt - 1;
}

int a[200001];
bool disabled[200001];
int cnt[32];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 0) continue;
		cnt[cntbit(a[i])]++;
	}
	int ans = 0;
	for (int i = 30; i >= 0; i--) {
		cnt[i] += cnt[i + 1];
		if (cnt[i] >= m) {
			ans += 1 << i;
			memset(cnt, 0, sizeof(cnt));
			for (int j = 1; j <= n; j++) {
				if (a[j] >= (1 << i) && ! disabled[j]) {
					for (int k = i; k <= 30; k++) {
						a[j] &= ~ (1 << k);
					}
					if (a[j] == 0) continue;
					cnt[cntbit(a[j])]++;
				} else {
					disabled[j] = true;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
