#include<bits/stdc++.h>
#define ll long long
#define f(i,a,b,n) for(ll i=a;i<=b;i+=n)
using namespace std;
ll n,m,a[500005],ans=1,now,nowsum;
void SoRt(ll l,ll r){
	if(l==r) return ;
	ll mid=(l+r)>>1;
	SoRt(l,mid);
	SoRt(mid+1,r);
	ll L=l,R=mid+1;
	vector<ll> v;
	while(L<=mid&&R<=r)
		if(a[L]<a[R]) v.push_back(a[L++]);
		else v.push_back(a[R++]);
	while(L<=mid) v.push_back(a[L++]);
	while(R<=r) v.push_back(a[R++]);
	f(i,l,r,1) a[i]=v[i-l];
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	f(i,1,n,1) scanf("%lld",&a[i]);
	SoRt(1,n);
	f(i,2,n,1){
		nowsum+=(i-now-1)*(a[i]-a[i-1]);
		while(nowsum>m) nowsum-=a[i]-a[++now];
		ans=max(ans,i-now);
	}
	printf("%lld",ans);
	return 0;
}
