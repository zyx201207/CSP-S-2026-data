#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		b[i]=a[i];
		for(int j=1;j<=n;j++) {
			if(a[i]==b[j]) {
				for(int k=j;k<=n;k++) {
					b[k]=0;
				}
			}
		} 
	}
	for(int i=1;i<=m;i++) {
		if(b[i]==i) cout<<i<<" ";
		else cout<<0<<" ";
	}
	return 0;
}
