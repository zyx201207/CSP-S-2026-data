#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+100;
ll n,k,a[N],c[N],s[N],ans=-1;
bool check(ll mid){
	ll x=0;
	for(ll i=1;i<=mid;i++)
		x+=i*c[i];
	for(ll i=1;i<=n-mid;i++){
		if(x<=k) return 1;
		x-=s[i+mid-1]-s[i-1];
		x+=c[i+mid]*mid;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
		s[i]=s[i-1]+c[i];
	}
	ll l=0,r=n-1,mid,ans=-1;
	while(l<=r){
		mid=(l+r)/2ll;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans+1;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
