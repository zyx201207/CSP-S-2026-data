#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,txa,txb,txc;
ll a[500005];
bool cmp(ll x,ll y) { 
	return x>y; 
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal .out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		if (a[i]>0) txc=1;
		if (a[i]!=a[i-1] && i>1) txa=1;
		if (a[i]-a[i-1] !=a[i-1]-a[i-2] && i>2) txb=1;
	} 
	sort(a+1,a+n+1,cmp);
	if (txc==0) {
		cout<<a[1]+m;
		return 0;
	} 
	if (txa==0) {
		if ((a[1]+m/n)*n>(a[1]+m/n+(n-m))*(n-m)) {
			cout<<(a[1]+m/n)*n;
		} else {
			cout<<(a[1]+n/m+(n-m))*(n-m);
		}
		return 0;
	}
	if (txb==0) {
		ll js=1,ls=m;
		for (int i=1;i<=n;i++) {
			if (a[1]-a[i]>=ls) {
				js++;
				ls-=a[1]-a[i];
			}
		}
		cout<<(a[1]+ls/m)*js;
		return 0; 
	}
	cout<<3; 
	return 0;
} 
