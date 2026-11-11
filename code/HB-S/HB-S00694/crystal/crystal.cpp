#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,a[N];
ull m;
bool chack(ll x){
	ull sum=0;
	for(ll i=1;i<=x;i++){
		sum+=a[x]-a[i];
	}
	return sum<=m;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	
	ll l=1,r=n;
	while(l+1!=r){
		ll mid=(l+r)/2;
		if(chack(mid)) l=mid;
		else r=mid;
		//cout<<"*l:"<<l<<" *r:"<<r<<endl;
	}
	cout<<l;
	return 0;
}
