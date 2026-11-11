#include <cstring>
#include <iostream>
using namespace std;
int n;
long long l, la, ls, r, ra, rs, sum, ans, mid, a[200005];
char b[200005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		sum += a[i];
	}
	mid = sum / 2;
	l = 0;
	r = 0;
	la = 1;
	ra = n;
	ls = a[1];
	rs = a[n];
	while(l + r < sum) {
		if(ls > rs) {
			l = rs;
			if(b[la] != b[ra]) {
				ans += rs - r;
			}
			r = rs;
			ra--;
			rs += a[ra];
		} else {
			r = ls;
			if(b[la] != b[ra]) {
				ans += ls - l;
			}
			l = ls;
			la++;
			ls += a[la];
		}
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
