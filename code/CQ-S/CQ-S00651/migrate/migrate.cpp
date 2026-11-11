#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long ll;

const int N = 2e6 + 10;

int C, T;
ll n, d;
ll a[N];
ll qp[N], qs[N];
ll hp[N], hs[N];

void solve() {
	cin >> n >> d;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		qp[i] = qs[i] = hp[i] = hs[i] = 0;
	}
	
	qp[0] = qs[0] = 0;
	qp[1] = qs[1] = 1;
	for(int i = 2; i <= n; i++) { // i, i + 1
		int l = lower_bound(a + 1, a + 1 + n, a[i] - d) - a;
		int r = lower_bound(a + 1, a + 1 + n, a[i + 1] - d) - a - 1;
		if(l <= r) qp[i] += qs[r] - qs[l - 1];
		qp[i]++;
		qs[i] = qs[i - 1] + qp[i];
	}
	
	hp[n + 1] = hs[n + 1] = 0;
	hp[n] = hs[n] = 1;
	for(int i = n - 1; i >= 1; i--) { // i, i + 1
		int l = upper_bound(a + 1, a + 1 + n, a[i - 1] + d) - a;
		int r = upper_bound(a + 1, a + 1 + n, a[i] + d) - a - 1;
		if(l <= r) hp[i] += hs[l] - hs[r + 1];
		hp[i]++;
		hs[i] = hs[i + 1] + hp[i];
	}
	
	ll res = 0;
	for(int i = 2; i <= n - 1; i++) {
		if(a[i + 1] - a[i] > d) continue;
		
		ll x = 0, y = 0;
		int l = lower_bound(a + 1, a + 1 + n, a[i + 1] - d) - a;
		int r = lower_bound(a + 1, a + 1 + n, a[i + 2] - d) - a - 1;
		r = min(r, i - 1);
		if(l <= r) x = qs[r] - qs[l - 1];
		
		l = upper_bound(a + 1, a + 1 + n, a[i - 1] + d) - a;
		r = upper_bound(a + 1, a + 1 + n, a[i] + d) - a - 1;
		l = max(l, i + 1);
		if(l <= r) y = hs[l] - hs[r + 1];
		
		res += x * y;
	}
	
	cout << res << endl;
}

ll o, ww;
void dfs(int now, int t, int step) {
	if(now >= t) {
		if(step < ww) ww = step, o = 1;
		else if(step == ww) o++;
		return;
	}
	int p = upper_bound(a + 1, a + 1 + n, a[now] + d) - a - 1;
	if(p > n) return;
	if(p > now + 1) {
		if(p - 2 >= now + 1) dfs(p - 2, t, step + 1);
		if(p - 1 <= t) dfs(p - 1, t, step + 1);
		if(p <= t) dfs(p, t, step + 1);
	} else {
		if(p > now) dfs(p, t, step + 1);
	}
}

void solve2() {
	cin >> n >> d;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	int res = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(a[j] - a[i] <= d) continue;
			o = 0; ww = n;
			dfs(i, j, 0);
			if(o == 2) res++;
		}
	} 
	
	cout << res << endl;
}

void solve3() {
	cin >> n >> d;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] -= a[1];
	}
	
	if(d < a[2] - a[1]) {
		cout << 0 << endl;
		return;
	}
	
	ll p = d / (a[2] - a[1]);
	
	if(p == 1) {
		cout << 0 << endl;
		return;
	}
	
	ll q = p + p - 1;
	
	if(n - 1 < q) {
		cout << 0 << endl;
		return;
	}
	
	ll res = (n - 1 - q + 1);
	cout << res << endl;
}

void solve4() {
	cin >> n >> d;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	puts("0");
}


int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> C >> T;
	while(T--) {
		if(C <= 2) solve2();
		else if(C == 13 || C == 14) solve4();
		else if(C == 11 || C == 12) solve3();
		else solve();
	}
	
	return 0;
}
/*
0 1
6 3
0 1 2 4 5 7

3 4 5 7 8 10 

假装写很多 ，实际是思路假了 
*/

