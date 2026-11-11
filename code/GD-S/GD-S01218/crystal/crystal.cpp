#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],b[2][500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=0;i<n;i++)	scanf("%lld",&a[i]);
	ll i=1,ans;
	sort(a,a+n);
	while(i<=n){
		for(ll j=i;j<n;j++) b[1][j]=b[0][j]+a[j]-a[j-i];
		ll min_=1e18+1;
		for(ll j=i;j<n;j++) min_=min(min_,b[1][j]);
		for(ll j=0;j<n;j++) b[0][j]=b[1][j];
		if(min_<=m) ans=++i;
		else break;
	}
	printf("%lld",ans);
	return 0;
}
