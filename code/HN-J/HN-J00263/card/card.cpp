#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

int a[N], n, m, pre[N], t[N];
int ans[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		map<int, int> mp;
		memset(pre, 0, sizeof pre);
		memset(t, 0, sizeof t);
		int cnt = 0;
		for (int j = i; j <= n; ++j) {
			if (!mp[a[j]]) {
				mp[a[j]] = 1;
				pre[a[j]] = ++cnt;
				t[cnt] = a[j];
			}
			else {
				int pos = pre[a[j]];
				for (int k = pos + 1; k <= cnt; ++k) {
					mp[t[k]] = 0;
					pre[t[k]] = 0;
				}
				cnt = pos;
			}
		}
		for (int j = 1; j <= cnt; ++j) {
			ans[t[j]]++;
		}
	}
	for (int i = 1; i <= m; ++i) {
		cout << ans[i] << " "; 
	}
	return 0;
}

