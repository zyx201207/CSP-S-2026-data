#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,c=0,ma=-1;
	cin>>n>>m;
	int a[n],b[(1+n)*n/2];
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			c++;
	    	b[c]=a[i]&a[j];
	    }
	}
	for(int i=1;i<=c;i++)ma=max(ma,b[i]);
	cout<<ma;
 return 0;
}
