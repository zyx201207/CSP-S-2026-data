#include<bits/stdc++.h>
int n,m,a[514514],ans[514514],c[514514],kz;
using namespace std;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			for(int k=j; k<=kz; k++) {
				if(c[k]==a[j]) {
					for(int ij=k; ij<=kz; ij++) {
						c[ij]==-1,kz--;
					}
				}	
			} 
			kz++;
			c[kz]=a[j];
		}
		for(int j=1; j<=kz; j++) if(c[j]!=0) ans[j]++;
	}
	for(int i=1; i<=m; i++) cout<<ans[i]<<" ";
	return 0;
} 
/*
4 3
1 2 1 3
*/
