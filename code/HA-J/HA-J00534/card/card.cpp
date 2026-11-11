#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005],c[500005];
bool f[500005];
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	int q;
	while(n>1) {
	    q=1;
		for(int i=q-1; i<=n; i++) {
			if(f[a[i]]==1) {
				f[a[i]]=0;
				for(int j=i-1; j>=1; j--) {
					f[a[j]]=0;
					a[j]=0;
				}
			}
			else f[a[i]]=1;
		}
		int o=n;
		for(int j=1; j<=n; j++) {
			if(a[j]==0)o--;
			c[j]=a[j];
			for(int i=1; i<=m; i++) {
				if(a[j]==i)b[i]++;
			}
		}
		for(int i=1; i<=n; i++) {
			if(c[i]!=0)a[i]=c[i];
		}
		n=o;
		q++;
	}
	for(int i=1; i<=m; i++)cout<<b[i]<<" ";
	return 0;
}
/*
4 3
1 2 1 3


*/
