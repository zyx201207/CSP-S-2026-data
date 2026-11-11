#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000]={0},b[1000]={0},d[1000]={0},c=0;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	for(int i=0;i<n;i++) {
		c=0;
		for(int j=i;j<n;j++) {
			d[c]=a[j];
			c++;
			for(int k=i;k<j;k++) {
				if(a[k]==a[j]) {
					for(int l=0;l<c;l++)
						d[l]=0;					
					c=0;
					d[c]=a[k];
					c++;
					break;
				}
			}
		}
		for(int j=1;j<=m;j++) {
			for(int k=0;k<c;k++) {
				if(d[k]==j)
					b[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++) {
		cout<<b[i]<<' ';
	}
	return 0;
}
