//GZ-S00028 遵义市第四初级中学 廖奕德
#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500001],b[500001],s,x,f,i;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1; i<=n; i++) {
		cin>>a[i];
		if(i==2)
			x=a[2]-a[1];
		if(i>2&&a[i]-a[i-1]!=x)
			f=1;
	}
	if(!f) {
		for(i=1; i<=n; i++)
			if(m*2<(1+(i-1))*(i-1)*x) {
				cout <<i-1;
				return 0;
			}
		cout <<n;
		return 0;
	}
	sort(a+1,a+n+1);
	for(i=2; i<=n; i++)
		b[i]=(a[i]-a[i-1])*(i-1)+b[i-1];
	for(i=1; i<=n; i++)
		if(m<b[i]) {
			cout <<i-1;
			return 0;
		}
//	for(i=n; i>=1; i--)
//		if(b[i]>m)
//			s=max(s,i-(upper_bound(b+1,b+n+1,b[i]-m)-b-1)+1);
//		else {
//			cout <<max(i,s);
//			return 0;
//		}
}
