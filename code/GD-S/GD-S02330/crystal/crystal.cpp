#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500001],l=-1000000000000000000,r=1000000000000000000,t,y;
bool c(ll k){
	ll s=0;
	for(ll i=1;i<=n;i++){
		if(k>=a[i]) s+=k-a[i];
		if(s>m) return 0;
	}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) scanf("%lld",a+i);
	while(l<r){
		t=l+r+1>>1;
		if(c(t)) l=t;
		else r=t-1;
	}
	ll s=0;
	for(ll i=1;i<=n;i++) if(a[i]<=l) s++;
	cout<<s;
}
