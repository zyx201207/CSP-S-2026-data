#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500005],s[500005];
bool check(ll x){
	ll mn=0x3f3f3f3f3f3f3f3f;
	for(int i=x;i<=n;i++)mn=min(mn,a[i]*(x-1)-s[i-1]+s[i-x]);
	return mn<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	ll l=1,r=n,ans=0;
	while(l<=r){
		ll mid=l+r>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0; 
}
