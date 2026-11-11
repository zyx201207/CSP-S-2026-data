#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long l[N], r[N], n, ans, a[N], len, cur, d;
string tmp, s, res;
long long ch(long long x) { return len + 1 - x; }
void sol() {
	for (int i = 1; i <= n; i++) 
		while (a[i]--) 
			res += s[i];
	len = res.size();
	res = ' ' + res;
	for (int i = 1; i <= len / 2; i++) ans += (res[i] != res[ch(i)]);
	cout << ans << '\n';
	exit(0);
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	s = " ";
	for (long long i = 1; i <= n; i++) {
		cin >> a[i] >> tmp;
		s += tmp[0];
		l[i] = r[i - 1] + 1;
		r[i] = r[i - 1] + a[i];
		len += a[i];
		d = max(d, a[i]);
	}
	if (d <= 500) sol();
	cur = n;
	for (int i = 1; l[i] <= len / 2; i++) {
		while (ch(r[i]) > l[cur]) cur++;
		while (ch(r[i]) < l[cur]) {
			if (s[i] != s[cur]) ans += a[cur];
			cur--;
		}
		if (s[i] != s[cur]) ans += r[cur] - ch(r[i]) + 1;
		if (ch(r[i]) == l[cur]) cur--;
	}
	cout << ans << '\n';
	return 0;	
}
