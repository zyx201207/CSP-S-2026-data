#include <iostream>
#include <cstring>
using namespace std;
#define Write cin.tie(nullptr);
#define by cout.tie(nullptr);
#define ___NightDay___ ios::sync_with_stdio(0)
#define N 500005

int n, m, a[N], cnt[N], seq[N], l;
bool vis[2 * N];

int main() {
	Write by ___NightDay___;
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i ++) {
//		cout << i << endl;
		l = 0;
		memset(vis, 0, sizeof(vis));
		for (int j = i; j <= n; j ++) {
			if (vis[a[j]]) {
				while (a[j] != seq[l] && l >= 0) {
					l --;
				}
			} else {
				l ++;
				seq[l] = a[j];
				vis[a[j]] = 1;
			}
		}
		for (int j = 1; j <= l; j ++) {
			cnt[seq[j]] ++;
		}
	}
	for (int i = 1; i <= m; i ++) {
		cout << cnt[i] << ' ';
	}
	return 0;
}

// 12pts

