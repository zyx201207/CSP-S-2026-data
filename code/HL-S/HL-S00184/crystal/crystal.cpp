#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m;
ll a[N],s[N];
bool check(int x){
	for(int i=1;i+x-1<=n;i++){
		if(a[i+x-1]*x-s[i+x-1]+s[i-1]<=m){
			return true;
		}
	}
	return false;
}
ll erfen(){
	ll l=1,r=n;
	while(l<r){
		ll mid=(l+r+1)>>1;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	s[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	cout<<erfen();
	return 0;
}

