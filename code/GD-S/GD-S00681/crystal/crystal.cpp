#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define st string 
ll n,k,s[500050];
bool check(ll x){
	ll ans=0,fir=1,sec=x,minn=1e18+5;
	for(ll i=1;i<=x;i++)
		ans+=s[x]-s[i];
	sec=x; 
	for(;sec<n;){
		minn=min(minn,ans);
		ans-=(s[sec]-s[fir]);
		ans+=(x-1)*(s[sec+1]-s[sec]);
		fir++,sec++;	
	}
	minn=min(minn,ans);
	if(minn<=k)
		return true;
	else
		return false; 
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
		cin>>s[i];
	sort(s+1,s+1+n);
	ll l=1,r=n,mid;
	while(l<r){
		mid=(l+r+1)/2;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	cout<<l;
	return 0;
} 
