#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n;
ll m;
int ans;
ll ma=-0x3f3f3f3f3f3f3f3f;
const int N=5e5+5;
ll a[N];
ll s2[N];
ll diff[N];
ll BS(int s){
	ll l=1,r=n;
	ll mid=-1;
	while(l<=r){
		mid=(l+r)>>1;
		if(s2[mid]-s2[s-1]-(mid-s+1)*(ma-a[mid])>m)r=mid-1;
		else l=mid+1;
	}
	return mid;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);	
	}
	ans=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)diff[i]=ma-a[i];
	for(int i=1;i<=n;i++)s2[i]=s2[i-1]+diff[i];
	for(int i=1;i<=n;i++){
		int pos=BS(i);
		ans=max(ans,pos-i+1);
	}
	cout<<ans-1;
	return 0;
} 
