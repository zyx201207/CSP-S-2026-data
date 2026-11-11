#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std; bool MEM;
using ll=long long; using ld=long double;
using pii=pair<int,int>; using pll=pair<ll,ll>;
const int I=1e9;
const ll J=1e18,N=5e5+7;
ll n,m,a[N],sum[N],ans;
void mian() {
	scanf("%lld%lld",&n,&m);
	for (ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for (ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for (ll cl=1,cr;cl<=n;cl=cr+1) {
		for (cr=cl;cr+1<=n&&a[cr+1]==a[cr];cr++);
		ll l=1,r=cl,mid,res=1;
		while (l<=r) {
			mid=l+r>>1;
			if (a[cl]*(cl-mid)-(sum[cl-1]-sum[mid-1])<=m) res=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,cr-res+1);
	}
	cout<<ans;
}
bool ORY; int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	int t; for (scanf("%d",&t);t--;)
	mian();
	cerr<<"\n"<<abs(&MEM-&ORY)/1048576<<"MB";
	return 0;
}
/*
Ç©µ½ 
*/
