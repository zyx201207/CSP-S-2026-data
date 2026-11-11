#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 1;
int a[N];
char c[N];
int cnt[26];
string s;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
	}
	long long ans = 0;
	int l = 0, r = n - 1;
	while (l < r) {
		if (a[l] == 0) l++;
		if (a[r] == 0) r--;
		int m = min(a[l], a[r]);
		if (c[l] != c[r]) ans += m;
		a[l] -= m;
		a[r] -= m;
	}
	cout << ans;
	return 0;
}
