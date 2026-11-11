#include <bits/stdc++.h>
#define inc(i, l, r) for(long long i = l; i <= r; ++i)
#define dec(i, l, r) for(long long i = l; i >= r; --i)
using namespace std;

const int N = 2 * 1e5 + 5;
int n, ans;
long long ap[N], a[N], tot, tot2;
char cp[N], c[N];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	inc(i, 1, n) {
		cin >> ap[i] >> cp[i];
		if(cp[i] != cp[i - 1]) {
			a[++tot] = ap[i]; c[++tot2] = cp[i];
		} else {
			a[tot2] += ap[i];
		}
	}
	
	for(long long i = 1; i <= tot / 2; i++) {
		long long j = tot + 1 - i;
		if(c[i] != c[j]) ans += min(a[i], a[j]);
		ans += abs(a[j] - a[i]);
	}
	cout << ans << '\n';
	return 0;
} 
