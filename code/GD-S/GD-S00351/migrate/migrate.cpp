#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000050;
int T, n, m, i, j, k, a[N], b[N], c[N], q[N], h[N], head;
long long ans;
void in(int &k) {
	char c = getchar();
	int s = 0, f = 0;
	while (c < '0' || c > '9') {
		if (c == '-') f = 1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') s = (s<<1)+(s<<3)+c-48, c = getchar();
	if (f) k = -s;
	else k = s;
}
vector<int> t;
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	in(T), in(T);
	while (T--) {
		t.clear();
		in(n), in(m);
		for (i=1; i<=n; i++) in(a[i]);
		t.clear(), head = ans = 0;
		for (i=n; i; i--) {
			b[i] = c[i] = 0;
			while (head < t.size() && a[t[head]]-a[i] > m) head++;
			b[i] = head < t.size() ? t[head] : 0;
			if (b[b[i]]) {
				if (b[i]-1 > i && b[b[i]-1] == b[b[i]]) c[i]++;
				if (b[i]-2 > i && b[b[i]-2] == b[b[i]]) c[i]++;
			}
			t.push_back(i);
		}
		for (i=1; i<=n; i++) {
			q[i] = h[i] = 1;
//			printf("%d %d %d\n", b[i], b[b[i]-1], b[b[i]-2]);
			if (b[b[i]] && b[i] > i+1) ans += b[b[i]-1]-b[b[i]-2];
		}
		for (i=1; i<=n; i++) {
			if (b[b[i]] && b[b[i]-1] != b[b[i]]) q[b[i]] += q[i];
		}
		for (i=n; i; i--) {
			if (b[b[i]] && b[b[i]-1] < b[b[i]]-1) q[b[i]] += q[i];
			q[i] = 1;
		}
		for (i=n; i; i--) {
			if (b[b[i]] && b[b[i]-1] != b[b[i]]) h[i] += h[b[i]]+b[b[i]]-1-b[b[i]-1];
		}
		for (i=1; i<=n; i++) {
//			printf("%d %d %d %d\n", ans, c[i], h[b[i]], q[i]);
			if (c[i] == 1) ans += h[b[i]]*q[i], ans--;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

