#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll n,a[500005],m;
int main(){
//	freopen("crystal4.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	ll ds=0;
	ll ans=0;
	for(ll i=1,j=1;i<=n;i++){
		ds+=a[i];
		while(j<i&&a[i]*(i-j+1)-ds>m){
			ds-=a[j];
			j++;
		}
		ans=max(ans,i-j+1);
	}
	printf("%lld",ans);
	return 0;
}
