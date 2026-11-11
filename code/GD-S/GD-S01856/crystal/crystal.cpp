#include <bits/stdc++.h>
using namespace std;
#define int long long

int read() {
	int aa = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch=='-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		aa = (aa<<3) + (aa<<1) + (ch^48);
		ch = getchar();
	}
	return aa*f;
}

const int N = 5e5+10;

int n, m, ans;
int a[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1;i<=n;i++)
		a[i] = read();
	sort(a+1, a+n+1);
	int l = 1, r = 1, s = 0;
	while(r <= n) {
		s += a[r];
		int tot = (r-l+1)*a[r];
		while(tot-s>m && l<=r) {
			tot -= a[r];
			s -= a[l];
			l++;
		}
		ans = max(ans, r-l+1);
		r++;
	}
	cout<<ans;
	return 0;
}
