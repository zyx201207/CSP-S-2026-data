#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=1e6+100;
ll n,m;
ll a[MAXN],b[MAXN],c[MAXN];
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
	c[1]=b[1]=a[2]-a[1];
//	cerr<<b[1]<<' '<<c[1]<<'\n';
	for(int i=2; i<=n-1; i++) {
		b[i]=a[i+1]-a[i];
		c[i]=c[i-1]+b[i];
//		cerr<<b[i]<<' '<<c[i]<<'\n';
	}
	ll ans=0,tot=0;
	for(ll l=1,r=1; r<=n; r++) {
		tot+=(r-l)*b[r-1];
//		cerr<<"r="<<r<<" tot="<<tot<<'\n';
		while(tot>m and l<=r) {
			tot-=c[r-1]-c[l-1];
			l++;
		}
//		cerr<<"l="<<l<<" tot="<<tot<<'\n';
		ans=max(r-l+1,ans);
	}
	cout<<ans;
	return 0;
}