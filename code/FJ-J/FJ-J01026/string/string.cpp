#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL n, middle, aa[200005];

char cc[200005];

string s, s1, s2;

struct node {
	LL l, r;
	char c;
} a[200005];

vector< node > ft, bk;

bool cmp(node a, node b) {
	return a.l < b.l;
}

void solve() {
	
	LL ans = 0;
	
	for (LL i = 0, j = 0; i < (LL)bk.size() && j < (LL)ft.size(); ) {
		if (bk[i].c == ft[j].c) {
			i ++, j ++;
		} else if (ft[j].l < bk[i].l && ft[j].r < bk[i].l) {
			i ++;
			continue;
		} else if (ft[j].l < bk[i].l && ft[j].r >= bk[i].l) {
			ans += ft[j].r - bk[i].l + 1; j ++; 
		} else if (ft[j].l <= bk[i].r && ft[j].r <= bk[i].r) {
			ans += ft[j].r - ft[j].l + 1; i ++, j ++; 
		} else if (ft[j].l <= bk[i].r && ft[j].r > bk[i].r) {
			ans += bk[i].r - ft[j].l + 1; i ++; 
		} else {
//			j ++;
//			cout << ft[j].l << ' ' << ft[j].r << endl << bk[i].l << ' ' << bk[i].r << endl;
			continue;
		}
//		cout << ans << endl;
	}	
	
	cout << ans << endl;
}

void solve1() {
	
	LL tn = n;
	
	for (LL i = 1; i <= n; i ++) {
		if (a[i].l <= middle && a[i].r >= middle) {
			if (a[i].l < middle) 
				a[++ tn] = {a[i].l, middle - 1, a[i].c};
			if (a[i].r > middle)
				a[++ tn] = {middle + 1, a[i].r, a[i].c};
			a[i].l = a[i].r = 0x3f3f3f3f;
			break;
		}
	}
	
	sort(a + 1, a + 1 + tn, cmp);
	
	for (LL i = 1; i <= n; i ++) {
		if (a[i].r <= middle)
			ft.push_back(a[i]);
		else
			bk.push_back(a[i]);
	}
	
	for (LL i = 0, now = 0; i < (LL)bk.size(); i ++) {
		LL len = bk[i].r - bk[i].l + 1;
		bk[i] = {now, now + len - 1, bk[i].c};
		now = bk[i].r + 1;
	}
	
	solve();
}

void solve2() {
	
	LL tn = n;
	
	for (LL i = 1; i <= n; i ++) {
		if (a[i].l <= middle && a[i].r >= middle) {
			if (a[i].l < middle) 
				a[++ tn] = {a[i].l, middle, a[i].c};
			if (a[i].r >= middle)
				a[++ tn] = {middle, a[i].r, a[i].c};
			a[i].l = a[i].r = 0x3f3f3f3f;
			break;
		}
	}
	
	sort(a + 1, a + 1 + tn, cmp);
	
//	for (LL i = 1; i <= n; i ++) {
//		cout << a[i].l << ' ' << a[i].r << endl;
//	}
	
	for (LL i = 1; i <= n; i ++) {
		if (a[i].r <= middle)
			ft.push_back(a[i]);
		else
			bk.push_back(a[i]);
	}
	
	for (LL i = 0, now = 0; i < (LL)bk.size(); i ++) {
		LL len = bk[i].r - bk[i].l + 1;
		bk[i] = {now, now + len - 1, bk[i].c};
		now = bk[i].r + 1;
	}	
	
	solve(); 
}

int main() {
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	
	LL now = 0;
	for (LL i = 1; i <= n; i ++) {
		LL b; 
		char c;
		cin >> b >> c;
		aa[i] = b, cc[i] = c;
		a[i].l = now, a[i].r = now + b - 1, a[i].c = c;
		now += b;
	}
	
	if (now < 1e9) {
		
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= aa[i]; j ++) {
				s += cc[i];
			}
		}
		
		LL mid = s.size() / 2;
	
		if (s.size() % 2) {
			for (int i = 0; i < (int)s.size(); i ++) {
				if (i < mid) s1 += s[i];
				if (i > mid) s2 += s[i];
			}
		} else {
			for (int i = 0; i < (int)s.size(); i ++) {
				if (i <= mid) s1 += s[i];
				else s2 += s[i];
			}
		}
		
		LL ans = 0;
		for (int i = 0; i < (int)s1.size(); i ++) {
			ans += (s1[i] != s2[i]); 
		}
		
		cout << ans << endl;	
		
		return 0;
	}
	
	middle = now / 2;
	
	if (now % 2 == 1) {
			
		solve1();
	} else {
		
		solve2();
	}
	
	return 0;
}

/*
6
100 a
100 a
100 a
100 b
100 b
100 b
*/
