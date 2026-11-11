#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[500005],arr[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		arr[i]=arr[i-1]+a[i];
	}
	ll ans=0,l=1;
	for(ll i=1;i<=n;i++){
		while(l<i&&a[i]*(i-l+1)>m+arr[i]-arr[l-1]) l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
} 
