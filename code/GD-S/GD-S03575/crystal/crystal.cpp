#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,l,r,mid;
ll a[500100],sum[500100]; 

bool check(ll tot){
	for(int i=tot;i<=n;i++){
		if(m-((tot*a[i])-(sum[i]-sum[i-tot]))>=0) return 1;
	}
	return 0;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	l=1,r=n;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%lld\n",r);
	return 0;
}
