#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[500005],ans[500005];
bool f;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		t[a[i]]++;
	}
	for(int k=1; k<=n; k++) {
		f=0;
		for(int i=n; i>=k; i--) {
			if(t[a[i]]>1) {
				for(int j=i; j<=n; j++) {
					ans[a[j]]++;
				}
				f=1;
				continue;
			}
		}
		if(f==0) {
			for(int j=k; j<=n; j++) {
				ans[a[j]]++;
			}
		}
	}
	for(int i=1; i<=m; i++)
		cout<<ans[i]<<' ';
	return 0;
}
/*
1213
1000
1200
0010
0013
*/
