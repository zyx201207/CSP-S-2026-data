#include <bits/stdc++.h>
using namespace std;
long long d,n,m,a[2000005],ans;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> d;
	while(d--) {
		cin >> n >> m;
		for(int i=1;i<=n;i++) {
			cin >> a[i];
		}
		ans=n*(n-1)/2;
		for(int i=1;i<n;i++) {
			for(int j=i+1;j<=n;j++) {
				if(abs(a[i]-a[j])<=m) ans--;
			}
		}
		cout << ans << endl;
	}
	return 0;
}