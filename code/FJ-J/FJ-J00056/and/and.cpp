#include <bits/stdc++.h>
#define Flead(a,s,e,t) for (int a = s; a <= e; a += t)
#define Fgead(a,s,e,t) for (int a = s; a >= e; a -= t)
using namespace std;

int n, m, a[200005], tmp[200005];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("and.in", "r", stdin); freopen("and.out", "w", stdout);
	cin>>n>>m;
	Flead(i, 1, n, 1) cin>>a[i];
	sort(a+1, a+1+n);
	int ans = 0;
	Fgead(i, 31, 0, 1) {
		int tsz = 0;
		Flead(j, 1, n, 1) {
	    	if ((a[j] >> i) & 1) tmp[++tsz] = a[j];
		}
		if (tsz >= m) {
			ans |= (1<<i);
			memcpy(a+1, tmp+1, sizeof(int) * tsz);
			n = tsz;
		}
	}
	cout<<ans;
	return 0;
}
