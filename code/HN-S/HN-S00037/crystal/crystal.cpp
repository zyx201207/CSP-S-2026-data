#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e6 + 10;

int n, L;
ll m, a[N], s[N];

bool check(int mid) {
	ll res = 0, goal = a[mid];
//	for (int i = L; i <= mid; i++) res += goal - a[i];
	res = (mid - L + 1) * goal - (s[mid] - s[L - 1]);
	
	return res <= m;
}

int find() {
	int l = L - 1, r = n + 1;
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}
	
	return l;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	
	int ans = 0;
	for (L = 1; L <= n; L++) ans = max(ans, find() - L + 1);
	
	cout << ans << endl;

	return 0;
}
/*
19768503
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/ 
