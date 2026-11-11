#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N][25], mk[N], t[N], n, m;

void ch (int id, int x) {
	int idx = 0;
	while (x) {
		int now = (x & 1);
		x >>= 1;
		a[id][++ idx] = now;
	}
	return;
}

int main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> t[i];
		ch(i, t[i]);
	}
	for (int i = 20; i; i --) {
		int cnt = 0;
		for (int j = 1; j <= n; j ++) {
			if (a[j][i] && mk[j] == 0) cnt ++;
		}
		if (cnt == m) {
			for (int j = 1; j <= n; j ++) {
				if (a[j][i] == 0 && mk[j] == 0) mk[j] = 1;
			}
			break;
		}
		if (cnt > m) {
			for (int j = 1; j <= n; j ++) {
				if (a[j][i] == 0 && mk[j] == 0) mk[j] = 1;
			}
		}
	}
	int cnt = 0, ans = 0;
	for (int i = 1; i <= n; i ++) {
		if (cnt >= m) break;
		if (mk[i] == 0) {
			if (cnt == 0) ans = t[i];
			else ans = (ans & t[i]);
			cnt ++;
		}
	}
	cout << ans;
	return 0;
}

