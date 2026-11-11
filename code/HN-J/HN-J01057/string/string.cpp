#include<iostream>
#define ll long long
using namespace std;
const int MAXN = 2e5 + 5;
int n, pos;
ll ans, a[MAXN], alen, len;
char c[MAXN];
bool flag;
int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i] >> c[i];
		alen += a[i];
	}
	alen /= 2;
	pos = n;
	for (int i = 1; i <= n; i ++) {
		ll flen = a[i], rlen = 0, cnt = 0;
		len += a[i];
		if (len >= alen) {
			flen -= (len - alen);
			flag = true;
		}
		for (int j = pos; j >= 1; j --) {
			rlen += a[j];
			if (c[j] == c[i]) cnt += a[j];
			a[j] = 0;
			pos --;
			if (flen <= rlen) {
				a[j] = rlen - flen;
				rlen -= a[j];
				if (c[j] == c[i]) cnt -= a[j];
				pos ++;
				break;
			} 
		}
		ans += rlen - cnt;
		if (flag) break;
	}
	cout << ans;
	return 0;
} 

