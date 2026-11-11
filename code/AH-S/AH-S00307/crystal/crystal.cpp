#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[500005],ans;
unsigned long long sum[500005],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;i++)sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
	ll l=1;
	for(ll r=1;r<=n;r++){
		while(l<r&&sum[r]-sum[l-1]>m)l++;
		ans=max(ans,r-l+1);
	}printf("%lld",ans);
	return 0;
}
