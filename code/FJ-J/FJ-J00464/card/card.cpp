#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for(int i=1; i<=n; i++) {
		int h=i;
		while(h<=n) {
			for(int j=n; j>=h; j--) {
				if(a[j]==a[h]) {
					ans[a[h]]++;
					h=j+1;
					break;
				}
			}
		}
	}
	for(int i=1; i<=m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
