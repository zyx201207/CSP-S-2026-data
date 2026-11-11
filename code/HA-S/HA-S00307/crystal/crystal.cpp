#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,m,a[N],b[N],sum,ans;
bool check(ll l,ll r){
	ll sum=0;
	for(int i=l;i<=r;i++){
		sum+=b[r-1]-b[i-1];
		if(sum>m)return 0;
	}
	return 1;
}
ll find(int k){
	ll l=1,r=k;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid,k))r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		b[i]+=b[i-1];
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,i-find(i)+1);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
5 5
1 2 4 8 9
*/
