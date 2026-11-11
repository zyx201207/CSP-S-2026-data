#include<bits/stdc++.h>
#define ll long long
using namespace std;
//ten year oi one place no open long long meet comblae
ll n,m;
ll qz[500005];
ll k[500005];
bool chec(ll mid){
	for(ll i=1;i<=n-mid+1;i++){
		if(qz[i+mid-1]-qz[i-1]+m>=k[i+mid-1]*mid){
			return 1;
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>k[i];
	sort(k+1,k+1+n);
	for(ll i=1;i<=n;i++)qz[i]=qz[i-1]+k[i];
	ll l=1,r=n;
	while(l<r){
		ll mid=(l+r)/2;
		if(chec(mid)==1){l=mid+1;}
		else {r=mid;}
	}
	cout<<l-1;
	return 0;
}
