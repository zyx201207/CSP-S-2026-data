#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> a(n+1);
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a.begin()+1, a.end());
	vector<int> pre(n+1, 0);
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int ans=1, l, r, mid, flagl, flagr, suml, sumr;
	for (int i=1;i<=n;i++) {
		l=1, r=min(i-1, n-i);
		while (l<=r) {
			mid=(l+r)/2LL;
			flagl=i-mid, flagr=i+mid;
			suml=pre[i-1]-pre[flagl-1];
			sumr=pre[flagr]-pre[i];
			if (sumr-suml<=m) {
				l=mid+1;
				if ((sumr-suml+a[i]-a[flagl-1]<=m&&flagl>1)||(sumr-suml+a[flagr+1]-a[i]<=m&&flagr<n)) flagl--;
				ans=max(ans, flagr-flagl+1);
			} else r=mid-1;
		}
	}
	cout << ans << endl;
	return 0;
} 
