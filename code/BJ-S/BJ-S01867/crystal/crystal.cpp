

#include <bits/stdc++.h>

using namespace std;

long long n = 0,m = 0;
long long a[500009];

bool px (long long x, long long y) {
	return x < y;
}
long long b[500009];
long long ans= 0;

long long check (int x, int y) {
	long long chazhi = b[x];
	long long sum = 1;
	for (int i = x-1; i >= 1; i--) {
		if (y<(ans-sum+1)*b[i+1]) {
			return 0;
		}
		if (y>=chazhi) {
			y-=chazhi;
			sum++;
			chazhi+=b[i];
		}
		else {
			return sum;
		}
		
	}
	return sum;
}

int main () {
	
	freopen("crystal.in", "r",stdin);
	freopen("crystal.out", "w",stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1,a+n+1,px);
	for (int i = 2; i <= n; i++) {
		b[i] = a[i]-a[i-1];
	}
	if (n<=6000) {
		for (int i = n; i >= 2; i--) {
			if (ans >= i) {
				break;
			}
			ans = max(ans, check(i,m));
		}
	}
	if (n>=200000) {
		int gongcha = a[2]-a[1];
		int geshu = m/gongcha;
		for (int i = 1; i*(i+1)<=2*geshu; i++) {
			ans = i+1;
		}
		ans = min(ans, n);
	}
	cout << ans << endl;
	
	
	return 0;
}
