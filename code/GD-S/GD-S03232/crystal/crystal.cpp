#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MAXN=5e5+1;
ll n,m,a[MAXN],c[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll sumn=0;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<n;i++) sumn+=(a[n]-a[i]);
	if(sumn<=m){
		cout<<n;
		return 0;
	}
	ll ans=1;
	for(ll i=n;i>=1;i--){
		ll sum=0,p=1;
		for(ll j=i-1;j>=1;j--){
			if((a[i]-a[j])>m) break;
			sum+=(a[i]-a[j]);
			if(sum>m) break;
			p++;
		}
		ans=max(ans,p);
	}
	cout<<ans;
	return 0;
} 
