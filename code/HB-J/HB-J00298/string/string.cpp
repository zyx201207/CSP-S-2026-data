#include<bits/stdc++.h>
using namespace std;
long long n,a[200010];
char b[200010];
long long ans=0;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i=1;i<=n;i++) {
		cin >> a[i] >> b[i];
	}
	int l=1,r=n;
	while(l<r) {
		long long mn=min(a[l],a[r]);
		a[l]-=mn;
		a[r]-=mn;
		if (b[l]!=b[r]) {
			ans+=mn;
		}
		if (a[l]==0) {
			l++;
		}
		if (a[r]==0) {
			r--;
		}
	}
	cout << ans << endl;
	return 0;
}
