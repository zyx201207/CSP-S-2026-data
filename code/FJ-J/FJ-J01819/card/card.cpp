#include <bits/stdc++.h>
//#define int long long
using namespace std;

const int N = 5e5 + 2;

int n, m, a[N], b[N], c[N], ans[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) c[j] = 0;
		for (int j = i;j <= n;j++) b[j] = 0;
		for (int j = i;j <= n;j++) {
			if (c[a[j]] != 0)
				for (int k = c[a[j]];k <= j - 1;k++) b[k] = -1;
			c[a[j]] = j;
		}
		for (int j = i;j <= n;j++) {
			if (b[j] != -1) ans[a[j]]++;
		}
	}
	for (int i = 1;i <= m;i++) cout << ans[i] << " ";
	cout << endl;
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

#include <bits/stdc++.h>
//#define int long long
using namespace std;

const int N = 5e5 + 2;

int n, m, a[N], b[N], c[N], d[N], ans[N], v[N], add[N], t[N];
bool vis[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		if (!d[a[i]]) d[a[i]] = i;
	}
	for (int i = n;i >= 1;i--) {
		if (!c[a[i]]) c[a[i]] = i, v[i] = 1, add[i]--, add[n]++;
		else if (c[a[i]] == -1) c[a[i]] = i, v[i] = 1, add[i]--, add[-c[a[i]]]++;
		else {
			add[c[a[i]] - 1]--, add[n]++;
			for (int j = c[a[i]] - 1;j > i;j--)
				if (i < c[a[j]] && c[a[j]] <= c[a[i]] - 1) c[a[j]] = -i;
		}
	}
	for (int i = n;i >= 1;i--) cout << add[i] << " ";
	cout << endl;
	for (int i = n;i >= 1;i--) {
		t[i] = t[i + 1] + add[i];
		cout << t[i] << " ";
		ans[a[i]] += v[i] * (t[i] + 1);
//		cout << endl;
	}
	for (int i = 1;i <= m;i++) cout << ans[i] << " ";
	cout << endl;
	return 0;
}
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 
*/
