#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=500010,INF=1e18;
ll n,k,a[N],q[N];
bool checkk(ll x,ll y){
	return y*a[x]+q[x-y]-q[x]<=k;
}
bool check(ll x){
	for(int i=x;i<=n;i++){
		if(checkk(i,x))return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)q[i]=a[i]+q[i-1];
	ll l=1,r=n;
	while(l<r){
		ll mid=(l+r+1)>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	printf("%lld",l);
} 
