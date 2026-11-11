#include<bits/stdc++.h>
#define ll long long
const int N=5e5+5;
using namespace std;
ll n,m,a[N],ans,sum[N];
bool checkk(ll k){
	ll cnt=1e18;
	if(k>n) return 0;
	for(ll l=1,r=k; r<=n; l++,r++)
		cnt=min(cnt,a[r]*k-sum[r]+sum[l-1]);
	return cnt<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];
	ll l=1,r=n+1,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(checkk(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%lld",ans);
	return 0;
}
