#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	ll m,t;
	cin>>n>>m;
	ll a[n];
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
//	for(ll i=0;i<n;i++){
//		cout<<a[i]<<' ';
//	}
//	cout<<'\n';
	ll l,r;
	ll ans=0;
	for(r=n-1;r>=0;r--){
//		cout<<"r="<<r<<'\n';
		t=m;
		l=r;
		while(l>0){
			if(t<a[r]-a[l-1]) break;
			t-=a[r]-a[l-1];
			l--;
//			cout<<"\t t="<<t<<'\n';
//			cout<<"\t l="<<l<<'\n';
		}
//		cout<<"\t r-l+1="<<r-l+1<<'\n';
		ans=max(r-l+1,ans);
//		cout<<"\tans="<<ans<<'\n';
	}
	cout<<ans;
	
} 
