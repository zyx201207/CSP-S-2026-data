#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int rd() {
	int x = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

const int N = 5e5 + 5;
int n, m, a[N], p[N];
int x = 0;
//int mi = 1e12 + 5, mx = -mi, res, top;

//bool int cmp(int x, int y){
//	return x > y;
//}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = rd();
	m = rd();
	bool f = 1, f2 = 1, f3 = 0;
	for(int i = 1; i <= n; ++ i) {
		a[i] = rd();

//		if(a[i] < mi) top = i;
//		mi = min(mi, a[i]);
//		if(mx < a[i]) res = i;
//		mx = max(mx, a[i]);
		if(i > 1) {
			if(i == 2) {
				x = a[i] - a[i - 1];
			}
			if(x != a[i] - a[i - 1]) {
				f = 0;
			}
			if(a[i] != i) f2 = 0;
			if(a[i] != a[i - 1]) f3 = 0;
		}
	}
	if(n == 1) cout << "1" << '\n';
	if(f3) {
		cout << n << '\n';
		return 0;
	}
	int ans = 0;
	if(f2 && f) {
		for(int i = 1; i <= n; ++ i) {
			if((((1 + i) * i) / 2) <= m) {
				ans = i;
//				cout << (((1 + i) * i) / 2) << '\n';
			} else {
				break;
			}
		}
		cout << ans;
		return 0;
	} else if(f) {
		for(int i = 1; i <= n; ++ i) {
			if((((x + (i * x)) * i) / 2) <= m) {
				ans = i;
//				cout << (((x + (i * x)) * i) / 2) << " " << i << '\n';
			} else {
				break;
			}
		}
		cout << ans;
		return 0;
	} else {
//		for(int i = 1;i <= n;++ i) {
//			for(int j = m;j >= )
//		}
//		int mid = res + top >> 1LL;
//		int l = mid, r = mid + 1;
//		int x =
//		for(;l > 0 && r < 0; l --,r ++) {
//			if(a[l] != a[r]) {
//				ans ++;
//
//			}
//		}
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; ++ i) {
			p[i] = a[i] - a[i - 1];
//			cout << p[i] << '\n';
		}
		ans = 1;
		for(int i = 1; i <= n; ++ i) {
			for(int j = i; j <= n; ++ j) {
				int cnt = m;
				int num = 1;
				for(int k = i + 1; k <= j; ++ k) {
					cnt-= p[k];
					if(cnt < 0) {
						num = 0;
						break; 
					};
					num ++;
				}
				if(cnt < 0) break;
				ans = max(ans, num);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
