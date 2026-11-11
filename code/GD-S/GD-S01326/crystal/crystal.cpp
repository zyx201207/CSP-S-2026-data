#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
ll n,m,ans;
ll a[10000100],v[10000100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)v[i]=a[i]+v[i-1];
	for(ll i=1;i<=n;i++){
		if(a[i+1]==a[i])continue;
		ll l=1,r=i;
		while(l<r){
			ll mid=(l+r)/2;
			ll ck=(i-mid+1)*a[i]-(v[i]-v[mid-1]);
			if(ck>m)l=mid+1;
			else if(ck<m)r=mid;
			else if(ck==m||ck+a[mid-1]>m){
				ans=max(ans,i-mid+1);
				break;
			}
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
