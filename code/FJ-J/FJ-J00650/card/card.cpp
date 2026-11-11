#include<bits/stdc++.h>
#define int long long
using namespace std;

const int max_n = 1e6 + 5;
const int max_m = 5000 + 5;

int n, m;
int a[max_n], b[max_n], c[max_n], ans[max_n], last[max_n], tr[max_n], newlast[max_n];

inline int lowbit(int x) {
	return x & (-x);
}

inline void add(int x, int y) {
	while (x <= n) {
		tr[x] += y;
		x += lowbit(x);
	}
}

inline int query(int x) {
	int res = 0;
	while (x) {
		res += tr[x];
		x -= lowbit(x);
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	
	bool flaga = true;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[a[i]]++;
		last[i] = c[a[i]];
		c[a[i]] = max(c[a[i]], i);
		if (a[i] < a[i - 1]) flaga = false;
	}	
	
	if (flaga) {
		for (int i = 1; i <= m; i++) {
			cout << c[i] << " ";
		}
		return 0;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) tr[j] = 0;
		add(i, 1);
		for (int j = i; j <= n; j++) {
			newlast[j] = last[j];
			while (newlast[j] >= i && query(newlast[j]) < 1) newlast[j] = newlast[newlast[j]];
			if (newlast[j] < i) continue;
			add(newlast[j], -1), add(j, 1);
		}
		
		for (int i = 1; i <= m; i++) {
			if (query(c[i]) >= 1) {
				ans[i]++;
			}
		}
	}
	
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	
	return 0;
}