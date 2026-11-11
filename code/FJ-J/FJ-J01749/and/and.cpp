#include <iostream>
#include <algorithm>
using namespace std;
const int N=2e5+5;

int n, m, mx, mxc;
int a[N];

inline bool cmp (int x, int y) {
	return x>y;
}

int main () {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	ios::sync_with_stdio (0), cin.tie (0);
	cin>>n>>m;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
		mx=max (mx, a[i]);
	}
	while (mx) {
		mx>>=1;
		mxc++;
	}
	for (int i=mxc-1; i>=0; i--) {
		int res=0;
		for (int j=1; j<=n; j++) {
			if (a[j]==-5243) continue;
			if (a[j]>>i&1) res++;
		}
		if (res<m) continue;
		for (int j=1; j<=n; j++) {
			if (a[j]==-5243) continue;
			if ((a[j]>>i&1)==0) a[j]=-5243;
		}
	}
	sort (a+1, a+1+n, cmp);
	int ans=a[1];
	for (int i=2; i<=m; i++) ans&=a[i];
	cout<<ans;
	return 0;
}
//CSP-J RP++
//CCF, you're my dad.
