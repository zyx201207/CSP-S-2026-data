#include<bits/stdc++.h>
using namespace std;
using LL = long long;

LL read() {
	LL x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch=='-'), ch = getchar();
	while(isdigit(ch)) x = (x<<3)+(x<<1)+(ch^48), ch = getchar();
	return f ? -x : x;
}

const int N = 5e5+5;
int n, ans;
LL m, a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	sort(a+1, a+n+1, greater<LL>());

	LL t = 0;
	for(int l = 1, r = 0; l <= n; l++) {
		while(r < n && t <= m) {
			r++; t += a[l] - a[r];
		}
		if(t > m) t -= a[l]-a[r], r--;
		ans = max(ans, r-l+1);
		t -= (r-l+1)*(a[l]-a[l+1]);
	}

	printf("%d\n", ans);

	return 0;
}