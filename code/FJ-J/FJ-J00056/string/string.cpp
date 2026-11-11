#include <bits/stdc++.h>
#define int long long
#define min(a,b) ((a)<(b)?(a):(b))
#define Flead(a,s,e,t) for (int a = s; a <= e; a += t)
using namespace std;

int n, a[200005];
char c[200005];

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("string.in", "r", stdin); freopen("string.out", "w", stdout);
	cin>>n;
	Flead(i, 1, n, 1) cin>>a[i]>>c[i];
	int p1 = 1;
	int p2 = n;
	int ans = 0;
	while (p1 < p2) {
		int diff = min(a[p1], a[p2]);
		if (c[p1] != c[p2]) ans += diff;
		a[p1] -= diff;
		a[p2] -= diff;
		if (a[p1] == 0) p1++;
		if (a[p2] == 0) p2--;
	}
	cout<<ans;
	return 0;
}
