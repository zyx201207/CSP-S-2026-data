#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], v[N], pos[N], cnt[N];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int id = 1; id <= n; id++) {
			v[id] = -1;
			pos[id] = -1;
		}
		int j = 1;
		for (int k = i; k <= n; k++) {
			if (pos[a[k]] == -1) {
				pos[a[k]] = j;
				v[j++] = a[k];
			} else {
				for (int id = pos[a[k]]; id <= j; id++) {
					v[id] = -1;
					pos[v[id]] = -1;
				}
				pos[a[k]] = j;
				v[j++] = a[k];
			}
		}
		for (int i = 1; i <= j + 1; i++) cout << v[i] <<" ";
		cout << "\n";
		for (int i = 1; i <= j + 1; i++) if (v[i] != -1) cnt[v[i]]++;
	}
	for (int i = 1; i <= m; i++) cout << cnt[i] << " ";
	return 0;
}
