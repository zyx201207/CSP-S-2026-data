#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n,m,a[N],b[N],c[N],ans[N],f=1,d[N];
int main () {
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin >> n >> m;
	for ( int i = 1; i <= n; i++) {
		cin >> a[i];
		b[a[i]] = i;
		c[a[i]]++;
	}
	for ( int i = n; i >= 1;i--) {
		cout << i << " " << a[i] << " " << c[a[i]] << "\n";
		c[a[i]]--;
		if (c[a[i]]==0) {
			ans[a[i]] = i;
		} else {
			d[a[i]]=i;
			f = 1;
		}
		if (f&&!d[a[i]]) {
			ans[a[i]]=1;
		} else if (f&&d[a[i]])ans[a[i]]=i;
	}
	for ( int i =1; i <= m;i++) cout << ans[i] << "\n";
	return 0;
}
