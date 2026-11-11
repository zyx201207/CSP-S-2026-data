#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main (){
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	long long ans;
	for (int i=1;i<=n;i++) {
		long long x;
		while (m--) {
			for (int j=i+1;j<=n;j++) {
				x=a[i]&a[j];
			}
		}
		ans=max(ans,x);
	}
	cout << ans;
	return 0;
}
