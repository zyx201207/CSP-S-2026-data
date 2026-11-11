#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
const int N=5e5+9;
ll a[N];
ll n,m;
ll cnt;
ll ans,ans2;
bool check(ll s) {
	cnt=0;
	ans=0;
	for(ll i=0;i<n;i++) {
		if(a[i]<=s) {
			cnt+=s-a[i];
			ans++;
			if(cnt>m) return false;
		}
	}
	ans2=ans;
	return true;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll l,r;
	for(ll i=0;i<n;i++) {
		scanf("%lld",&a[i]);
		if(i) l=min(l,a[i]),r=max(r,a[i]);
		else l=r=a[i];
	}
	while(l<r) {
		ll mid=l+((r-l+1)>>1);
		if(check(mid)) l=mid;
		else r=mid-1;
//		cout<<l<<" "<<r<<"\n";
	}
	cout<<ans2;
	return 0;
} 

/*
5 5
2 1 2 4 8 9

5 8
-3 -1 2 2 7
*/
