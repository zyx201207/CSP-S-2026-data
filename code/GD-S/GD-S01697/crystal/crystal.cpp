#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+10;
ll a[N],s[N];ll n,m;
bool check(ll x){
	for(int i = x;i<=n;i++){
		ll t1=s[i]-s[i-x];
		ll t2=a[i]*x;
		if(t2-t1<=m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll l=1,r=n;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
}
