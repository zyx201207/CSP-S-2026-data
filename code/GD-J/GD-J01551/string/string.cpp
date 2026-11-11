#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ft first
#define sd second
const int N = 2e5 + 5;
int n, id, cnt, a[N], del[N];
char c[N];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i] >> c[i];
	for (int i = 1, j = n; i < j; ) {
		int si = a[i] - del[i], sj = a[j] - del[j];
		if (si > sj) {
			if (c[i] != c[j]) cnt += sj;
			j--, del[i] += sj;
		}
		else if (si == sj) {
			if (c[i] != c[j]) cnt += si;
			i++, j--;
		}
		else {
			if (c[i] != c[j]) cnt += si;
			i++, del[j] += si;
		}
	}
	cout << cnt;
	return 0;
}

