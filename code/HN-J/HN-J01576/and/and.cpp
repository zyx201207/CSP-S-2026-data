#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll n,m,a[N];
ll z2(ll x,ll y) {
	ll xx[35],yy[35];
	ll xxx[35],yyy[35];
	ll zz[35],zzz[35];
	for(ll i=1; i<35; i++) {
		xx[i]=xxx[i]=yy[i]=yyy[i]=zz[i]=zzz[i]=0;
	}
	ll xi=1,yi=1;
	while(x!=0) {
		xxx[xi]=x%2;
		x/=2;
		xi++;
	}
	while(y!=0) {
		yyy[yi]=y%2;
		y/=2;
		yi++;
	}
	xi--,yi--;
	for(ll i=1,j=xi; i<=xi,j>=1; i++,j--) {
		xx[i]=xxx[j];
	}
	for(ll i=1,j=yi; i<=yi,j>=1; i++,j--) {
		yy[i]=yyy[j];
	}
	if(xi==yi) {
		for(ll i=1; i<=max(xi,yi); i++) {
			if(xx[i] && yy[i]) {
				zz[i]=1;
			}
		}
		long long l=0,t=1;
		for(ll i=max(xi,yi); i>=1; i--) {
			l+=t*zz[i];
			t*=2;
		}
		return l;
	}else{
		for(ll i=max(xi,yi); i>=1; i--) {
			if(xx[i] && yy[i]) {
				zz[i]=1;
			}
		}
		for(ll i=1,j=max(xi,yi);i<=max(xi,yi) && j>=1;i++,j--){
			zzz[i]=zz[j];
		}
		long long l=0,t=1;
		for(ll i=max(xi,yi); i>=1; i--) {
			l+=t*zzz[i];
			t*=2;
		}
		return l;
	}
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<ll>());
	if(m==1) {
		cout<<a[1];
		return 0;
	}
	ll num=a[1];
	for(ll i=1; i<m; i++) {
		num=z2(num,a[i+1]);
	}
	cout<<num;
	return 0;
}

