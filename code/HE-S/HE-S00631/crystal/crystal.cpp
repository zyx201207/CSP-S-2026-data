#include <bits/stdc++.h>
using namespace std;
#define gc getchar()
#define pb push_back
typedef long long ll;
const int N=1e6+6;
ll rd() {
	ll x=0,f=1; char c=gc;
	for(;c<'0'||c>'9';c=gc)if(c=='-')f=-1;
	for(;c>='0'&&c<='9';x=x*10+c-'0',c=gc);
	return x*f;
}
ll n,m,ans,a[N],sum[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd(); m=rd();
	for(int i=1;i<=n;i++) a[i]=rd();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++) {
		int l=1,r=i,res=i;
		while(l<=r) {
			int mid=(l+r)/2;
			if((i-mid+1LL)*a[i]-(sum[i]-sum[mid-1])<=m) res=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-res+1LL);
	}
	cout<<ans<<'\n';
	return 0;
}
// fc crystal.out crystal1.ans
