#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5;
ll n,m,a[N+10];
bool check(ll x) {
	ll s=0,mi=1e18;
	for(int i=1;i<x;i++) 
		s+=a[x]-a[i];
	for(int i=x+1;i<=n;i++) {
		mi=min(mi,s);
		s=(a[i]-a[i-1])*x+s-(a[i]-a[i-x]);
	}
	return mi<=m;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=1,r=n+1; 
	while(l+1<r) {
		ll mid=(l+r)>>1;
		if(check(mid)==true) l=mid;
		else r=mid; 
	}
	cout<<l;
	
	return 0;
} 
