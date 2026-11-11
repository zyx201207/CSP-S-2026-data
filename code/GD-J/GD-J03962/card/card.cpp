#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5 + 10;
int a[N], st[N], top, cnt[N], ans[N], pos[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	bool flaga = true;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
		if (a[i - 1] > a[i]) flaga = false;
	}
	if (flaga) {
		for (int i = 1; i <= m; i++) {
			cout << pos[i] << ' ';
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		top = 0;
		for (int j = 1; j <= m; j++) {
			cnt[j] = 0;
		}
		for (int j = i; j <= n; j++) {
			if (cnt[a[j]]) {
				while (st[top] != a[j]) {
					--cnt[st[top]];
					--top;
				}
			} else {
				st[++top] = a[j];
				++cnt[a[j]];
			}
		}
		for (int j = 1; j <= m; j++) {
			if (cnt[j]) ++ans[j];
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}
