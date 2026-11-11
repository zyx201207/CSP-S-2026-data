#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],r,d,dis;
int ans=0;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++) {
		long long y;
		if(i==1) {
			for(int j=i+1; j<=n; j++) {
				y=y+(a[j]-a[j-1])*(j-i);
				if(y>m) {
					r=j;
					d=y;
					dis=a[j]-a[i];
					break;
				} else {
					ans=max(ans,j-i+1);
				}
			}
		} else {
			d=d-dis;
			if(d<=m) {
				y=d;
				for(int j=r; j<=n; j++) {
					if(j!=r) {
						y=y+(a[j]-a[j-1])*(j-i);
					}
					if(y>m) {
						r=j;
						d=y;
						dis=a[j]-a[i];
						break;
					} else {
						ans=max(ans,j-i+1);
					}
				}
			}
			else{
				dis=a[r]-a[i];
			}
		}
		y=0;
	}
	cout<<ans;
	return 0;
}
