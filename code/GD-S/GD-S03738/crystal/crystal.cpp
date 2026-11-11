#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+9;
ll n,m;
ll a[N];
ll pre[N];
bool check(ll mid){
	for(ll i=mid;i<=n;i++){
		if(mid*a[i]-(pre[i]-pre[i-mid])<=m){
			return true;
			break;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		pre[i]=pre[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	ll i=1,j=n;
	while(i<=j){
		ll mid=(i+j)>>1;
		if(check(mid)){
			i=mid+1;
		}
		else j=mid-1;
	}
	printf("%lld",i-1);
	return 0;
} 
