#include <bits/stdc++.h>
#define LL long long
#define sc(a) cout<<(a)<<"\n"
#define sx(a,b) cout<<(a)<<" "<<(b)<<"\n"
using namespace std ;
const int N=5e5+10 ;
LL n ;
LL a[N],p[N],m,ans ;
int main () {
//	system ("fc hh crystal4.ans") ;
	freopen ("crystal.in","r",stdin) ;
	freopen ("crystal.out","w",stdout) ;
//	freopen ("crystal4.in","r",stdin) ;
//	freopen ("hh","w",stdout) ;
	cin>>n>>m ;
	for (int i=1;i<=n;i++) {
		cin>>a[i] ;
	}
	sort (a+1,a+n+1) ;
	for (int i=1;i<=n;i++) {
		p[i]=p[i-1]+a[i] ;
	}
	for (LL i=1;i<=n;i++) {
		LL l=1,r=i,tp=-1 ;
		while (l<=r) {
			LL mid=(l+r)>>1 ;
			if (a[i]*(i-mid+1)-(p[i]-p[mid-1])<=m) r=mid-1,tp=mid ;
			else l=mid+1 ;
		}
		if (tp>=0) ans=max (ans,i-tp+1) ;
	}
	cout<<ans ;
	return 0 ;
} 
