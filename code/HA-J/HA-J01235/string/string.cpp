#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXN = 2 * 1e5 + 10;

struct hyw {
	ll sz;
	char c;
};

int n, tot, toto;
ll sum, cnt, res, cntt;
hyw a[MAXN];
char t;

int main () {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	bool flag = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].sz >> a[i].c;
		if (i == 1) t = a[i].c;
		else if (a[i].c != t) flag = 0;
		sum += a[i].sz;
	}
	if (flag) {
		cout << 0;
		return 0;
	}
	res = sum / 2;
	tot = 1, toto = n;
	while (res > 0) {
		if (a[tot].c == a[toto].c) {
			if (max (a[tot].sz, a[toto].sz) <= res) {
				cnt += min (a[tot].sz, a[toto].sz);
				res -= min (a[tot].sz, a[toto].sz);
				if (a[tot].sz < a[toto].sz) {
					a[toto].sz -= a[tot].sz;
					tot++;
				}
				else if (a[tot].sz > a[toto].sz) {
					a[tot].sz -= a[toto].sz;
					toto--;
				}
				else tot++, toto--;
			} else {
				ll t = max (a[tot].sz, a[toto].sz);
				if (a[tot].sz > a[toto].sz) a[tot].sz = res;
				else a[toto].sz = res;
				res -= min (a[tot].sz, a[toto].sz);
				if (a[tot].sz < a[toto].sz) {
					a[toto].sz -= a[tot].sz;
					tot++;
				}
				else if (a[tot].sz > a[toto].sz) {
					a[tot].sz -= a[toto].sz;
					toto--;
				}
				else tot++, toto--;
			}
		} else {
			if (max (a[tot].sz, a[toto].sz) <= res) {
				res -= min (a[tot].sz, a[toto].sz);
				if (a[tot].sz < a[toto].sz) {
					a[toto].sz -= a[tot].sz;
					tot++;
				}
				else if (a[tot].sz > a[toto].sz) {
					a[tot].sz -= a[toto].sz;
					toto--;
				}
				else tot++, toto--;
			} else {
				ll t = max (a[tot].sz, a[toto].sz);
				if (a[tot].sz > a[toto].sz) a[tot].sz = res;
				else a[toto].sz = res;
				res -= min (a[tot].sz, a[toto].sz);
				if (a[tot].sz < a[toto].sz) {
					a[toto].sz -= a[tot].sz;
					tot++;
				}
				else if (a[tot].sz > a[toto].sz) {
					a[tot].sz -= a[toto].sz;
					toto--;
				}
				else tot++, toto--;
			}
		}
	} 
	cout << sum / 2 - cnt;
	return 0;
}
