#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5e5+10;
ll read() {
	ll x;scanf("%lld",&x);return x;
}
ll a[N],b[N],sum[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n=read(),m=read(),ans=0;
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++) {
		int l=1,r=i,pos;
		while(l+1<r) {
			int mid=l+r>>1;
			if(a[i]*1ll*(i-mid+1)-(sum[i]-sum[mid-1])<=m) r=mid;
			else l=mid+1;
		}
		int mid=l+r>>1;
		if(a[i]*1ll*(i-mid+1)-(sum[i]-sum[mid-1])<=m) pos=mid;
		else pos=mid+1;
		ans=max(ans,1ll*(i-pos+1));
	}
	printf("%lld\n",ans);
	return 0;
}
