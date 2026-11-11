#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 10, MAXM = 3e5 + 10;
int a[MAXN], b[MAXM], nxt[MAXN], cnt[MAXM];
bool f[MAXN];
int main () {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	ios::sync_with_stdio (false), cin.tie (0), cout.tie (0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	for (int i = 1; i <= n; ++ i) {
		if (b[a[i]]) {
			nxt[b[a[i]]] = i;
		}
		b[a[i]] = i;
	}
	for (int i = 1; i <= n; ++ i) {
		if (f[i]) continue;
		int k = i, c = 1;
		while (k <= n) {
			if (nxt[k]) k = nxt[k], c += (!f[k]), f[k] = true;
			else {
				cnt[a[k]] += c, c += (!f[k + 1]), f[k + 1] = true, k ++;
			}
		}
	}
	for (int i = 1; i <= m; ++ i) cout << cnt[i] << " ";
		
	return 0;
}
//, cout << "TRUE:" << k << "\n"
//cout << i << " " << k << " : " << a[k] << " " << "  c : " << c << "  " << f[k + 1] << "\n";
