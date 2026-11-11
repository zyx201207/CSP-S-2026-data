#include<bits/stdc++.h>
#define endl '\n'
#define pi pair<int, int>
#define ll long long

using namespace std;
const int N = 5e5 + 10;
const int V = 3e5 + 10;
int n, m, a[N];
int f[N]; // f[i] 表示 i 后面离 i 最近的 a[i] 的下标
int mp[V], ans[V];

int main() {
  	freopen("card.in", "r", stdin);
  	freopen("card.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
//	for (int i = 1; i <= n; i++) {
//		f[mp[a[i]]] = i;
//		mp[a[i]] = i;
//	}
	for (int i = n; i >= 1; i--) {
		if (!mp[a[i]]) mp[a[i]] = i;
		else f[i] = mp[a[i]];
	}
//	for (int i = 1; i <= n; i++) cout << f[i] << " ";cout << endl;
	for (int i = 1; i <= n; i++) {
//		int p = i;
//		while (f[p]) p = f[p];
//		cout << i << " " << p << endl;
		if (a[i] == a[n]) ans[a[i]]++;
		else {
			int p = i;
			while (p <= n) {
				if (f[p] == 0) ans[a[p]]++, p++;
				else p = f[p];
//				cout << p << endl;
			}
		}
	}
	cout << ans[1];
	for (int i = 2; i <= m; i++) cout << " " << ans[i];
//	cout << endl;
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
