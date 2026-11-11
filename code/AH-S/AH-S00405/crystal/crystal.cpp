#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll a[N],n,m;
bool check(ll mid){
	ll sum=0;
	for(ll i=2;i<=n;i++){
		if(i>mid) sum-=a[i-1]-a[i-mid];
		sum+=(a[i]-a[i-1])*min(mid-1,i);
		if(i>mid&&sum<=m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	ll l=1,r=n+1;
	while(l<r){
		ll mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid;
	}
	cout<<r;
	return 0;
}
