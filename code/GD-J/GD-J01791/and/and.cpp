#include <bits/stdc++.h>
using namespace std;

#define int long long

int read() {
	int aa = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		aa = (aa << 3) + (aa << 1) + (ch ^ 48);
		ch = getchar();
	}
	return aa * f;
}

const int N = 2e5+10;

int n, m, ans;
int a[N];
bool f[N];
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1;i<=n;i++) {
		a[i] = read();
	}
	for(int i = 31;i>=0;i--) {
		int cnt = 0;
		for(int j = 1;j<=n;j++) {
			if(f[j])
				continue;
			if(a[j] & (1<<i))
				cnt++;
		}
		if(cnt >= m) {
			ans |= (1<<i);
			for(int j = 1;j<=n;j++) {
				if(f[j])
					continue;
				if(!(a[j] & (1<<i)))
					f[j] = 1;
			}
		}
	}
	cout<<ans;
	return 0;
}
