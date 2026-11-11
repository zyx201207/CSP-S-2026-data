#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
long long m;
long long a[500005],s[500005];
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;i ++) {
		cin>>a[i];
	}
	sort (a + 1,a + 1 + n);
	for (int i = 1;i <= n;i ++) {
		int l = 1,r = i,sum = i;
		s[i] = s[i - 1] + a[i];
		while (l <= r) {
			int mid = (l + r) / 2;
			if ((i - mid + 1ll) * a[i] - (s[i] - s[mid - 1]) <= m) {
				r = mid - 1;
				sum = mid;
			} else l = mid + 1;
		}
		ans = max(ans,i - sum + 1ll);
	}
	cout<<ans;
	fclose (stdin);
	fclose (stdout);
	return 0;
}
