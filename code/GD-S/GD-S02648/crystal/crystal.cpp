#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m;
ll a[N],s[N];
bool check(ll x){
	ll cnt=1e18+5;
	for(ll l=1;l+x-1<=n;l++){
		ll r=l+x-1;
		ll s1=s[r]-s[l-1],s2=1ll*x*a[r];
		cnt=min(cnt,s2-s1);
	}
	return abs(cnt)<=m;
}
bool check1(){
	ll d=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=d){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(check1()){
		ll d=a[2]-a[1];
		ll x=1,cnt=0;
		while(1){
			cnt++;
			ll num=d*(x*x+x)>>1ll;
			if(num>m||cnt>n){
				break;
			}
			x++;
		}
		cout<<x<<"\n";
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	ll l=1,r=n,ans;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans<<"\n";
	return 0;
} 
