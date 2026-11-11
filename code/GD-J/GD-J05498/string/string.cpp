#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
int n;
struct node {
	int x;
	char ch;
} a[N];
ll ans;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].ch;
	node l = a[1], r = a[n];
	int L = 1, R = n;
	while (L < R) 
		if (l.x > r.x) {
			l.x -= r.x;
			if (l.ch != r.ch) ans += r.x;
			r = a[--R];
		} else if (l.x == r.x) {
			if (l.ch != r.ch) ans += l.x;
			l = a[++L];
			r = a[--R]; 
		} else {
			r.x -= l.x;
			if (l.ch != r.ch) ans += l.x;
			l = a[++L];
		}
	cout << ans << endl;
 	return 0;
}

