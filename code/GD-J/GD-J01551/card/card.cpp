#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Max(a, b) a = max(a, b)
const int N = 5e5 + 5;
const int M = 3e5 + 5;
int n, m, a[N], cnt[M];
int in[M], st[N], tp, lst[M];//cs1
int r[M], sum;//csA, B
bool ckA() {
	for (int i = 1; i <= n; i++)
		if (a[i] > a[i + 1]) return 0;
	return 1;
}
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (ckA()) {
		for (int i = 1; i <= n; i++) 
			cnt[a[i]] = i;
	}
	else {
		for (int i = n; i >= 1; i--) {
			if (!lst[a[i]]) lst[a[i]] = i;
			for (int j = i; j <= n; j++) {
				in[a[j]] = 1;
				if (lst[a[j]]) j = lst[a[j]];
			}
			for (int j = 1; j <= m; j++) 
				if (in[j]) cnt[j]++, in[j] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << cnt[i];
		if (i < m) cout << " ";
	}
  	return 0;
}
