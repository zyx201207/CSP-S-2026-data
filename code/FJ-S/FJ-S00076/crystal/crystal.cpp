#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

//#define DEBUG
#ifdef DEBUG
#define debug(fmt,...) printf(fmt,##__VA_ARGS__)
#else
#define debug(fmt,...)
#endif

const ll INF = 1e12;

int n;
ll a[500005];
ll m;
ll d;

/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 5
-1 6 8 -3 3

5 4
1 2 3 4 5

6 10 
1 2 3 4 5 6

6 10 
4 5 6 7 8 9

5 7
4 6 8 10 12

6 24
4 9 14 19 24 29
*/

bool check(ll x) {
//	debug("x:%lld\n",x);
	for (int i = 1;i + x - 1 <= n;i++) {
		ll mid = a[i + x- 1];
		ll need = 0;
		for (int j = i;j <= i + x - 1;j++) {
			need += abs(a[j] - mid);
		}
//		debug("[%d,%lld],mid:%lld need:%lld\n",i,i + x - 1,mid,need);
		if (need <= m) {
			return true;
		}
	}
	return false;
}

bool check1(ll x) {
	ll fst = d;
	ll end = d + d * (x - 2);
//	debug("x:%lld fst:%lld end:%lld %lld\n",x,fst,end,(fst + end) * (x - 1) / 2);
	return (fst + end) * (x - 1) / 2 <= m;
}

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	bool flag = 0;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		if (i >= 3) {
			if (a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
				flag = 1;
			}
		}
	}
	sort(a + 1,a + n + 1);
//	debug("flag:%d\n",flag);
	if (flag) {
		int l = 0;
		int r = n + 1;
		while (l + 1 < r) {
			ll mid = l + (r - l) / 2;
			if (check(mid)) {
				l = mid;
			} else {
				r = mid;
			}
		}
		cout << l << endl;
	} else {
		ll l = 0;
		ll r = n + 1;
		d = a[2] - a[1];
		while (l + 1 < r) {
			ll mid = l + (r - l) / 2;
			if (check1(mid)) {
				l = mid;
			} else {
				r = mid;
			} 
		} 
		cout << l;
	}
	
	return 0;
} 
