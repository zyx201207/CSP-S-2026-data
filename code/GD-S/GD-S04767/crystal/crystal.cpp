#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500009],c[500009];
long long ps[500009];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2; i<=n; i++) {
		c[i]=a[i]-a[i-1];
	}
	for(int i=1; i<=n; i++) {
		ps[i]=ps[i-1]+c[i];
	}
	long long l=1,r=1,now=0;


	while(r<=n) {

		ans=max(ans,r-l+1);
		r++;
		now+=(r-l)*c[r];
		while(now>m) {
			l++;
			now-=ps[r]-ps[l-1];
		}
	}
	cout<<ans;
	return 0;
}
