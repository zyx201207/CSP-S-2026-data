#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],k;

bool c(ll w){
	ll l=0,r=n+1,o=m,t=0;
	while(l<=r){
		ll mid=l+(r-l)/2;
		if(a[mid]>=w){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	for(int i=l;i<=n&&a[i]==w;++i){
		t++;
	}
	for(int i=l-1;i>=1;--i){
		if(abs(w-a[i])<=o){
			o-=abs(w-a[i]);
			t++;
		}else{
			break;
		}
	}
	if(t>=k){
		k=max(k,t);
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=a[1],r=a[n];
	while(r-l>1){
		ll mid=l+(r-l)/2;
		if(c(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	ll p=k;
	k=0;
	l=a[1],r=a[n];
	while(r-l>1){
		ll mid=l+(r-l)/2;
		if(c(mid)){
			r=mid;
		}else{
			l=mid;
		}
	}
	cout<<max(p,k);
	return 0;
}
/*
5 5
1 2 3 4 5
*/
