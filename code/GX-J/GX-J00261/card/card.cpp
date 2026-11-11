#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int main () {
	freopen ("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++) {
		cin>>a[i];
		}
		b[a[n-1]]=n;
		if (m==n) {
			for (int l=0;l<m;l++) {
				cout<<l+1<<" ";
				}
				return 0;
			}
		if (m==1) {
			cout<<n;
			return 0;
			}
			int sum=n,max=0;
		while (sum>0) {
			for (int y=max;y<n;y++) {
				if (b[a[y]]==b[a[n-1]]) continue;
				b[a[y]]++;
			}
			sum--;
			max++;
			}
			for (int e=0;e<n;e++) {
				for (int f=e+1;f<n;f++) {
					if (a[e]==a[f]) {
						for (int g=e;g<f;g++) {
							b[g]--;
							}
						}
					}
				}
				for (int x=1;x<=m;x++) {
					if (b[x]==0) {
						m++;
						continue;
						}
						if (x==a[n-1]) {
							cout<<n;
							}
						cout<<b[x]<<" ";
					}
	return 0;
}
