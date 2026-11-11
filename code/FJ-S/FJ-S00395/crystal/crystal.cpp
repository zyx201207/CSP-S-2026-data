#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll w[1000006];
ll n,m;
ll qz[1000006];
ll ef(ll x){
	ll ans=x;
	ll g=w[x];
	ll l=1,r=x;
	while(l<=r){
		ll mid=(l+r)/2;
		if(qz[x-1]-qz[mid-1]+m<g*(x-mid)){
			l=mid+1;
		}
		else {
			r=mid-1;
			ans=mid;
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	sort(w+1,w+1+n);
	for(int i=1;i<=n;i++){
		qz[i]=qz[i-1]+w[i];
	}
	ll daan=1;
//	for(int i=1;i<=n;i++){
//		cout<<qz[i]<<" ";
//	}
//	cout<<"\n";
	for(int i=1;i<=n;i++){
		daan=max(daan,i-ef(i)+1);
//		cout<<i<<" "<<x<<" "<<daan<<"\n";
	}
	cout<<daan<<"\n";
	return 0;
}
