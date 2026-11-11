#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],ans=0;
char c[200005];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i] >> c[i];
	}
	int l=1,r=n;
	while(l<r) {
		if(c[l]!=c[r]) ans+=min(a[l],a[r]);
		if(a[l]>a[r]) a[l]-=a[r],r--;
		else if(a[l]==a[r]) l++,r--;
		else a[r]-=a[l],l++;
	}
	cout << ans;
	return 0;
}
