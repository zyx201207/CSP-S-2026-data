#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int n,m,ans,l,a[500010],b[500010];
signed main(void) {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	l=1;
	for (int i=1;i<=n;i++) {
		for (;;) {
			long long t=a[i]*(i-l+1)-(b[i]-b[l-1]);
			if (t<=m) break;
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout << ans;
	return 0;
}
