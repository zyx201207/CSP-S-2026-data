#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[500005],d[500005];
ll n,m;
bool check(ll x,ll k){
	ll sum=x*(x-1)/2;
	if(sum*k<=m){
		return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f=1;
	ll k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	k=labs(a[2]-a[1]);
	for(int i=2;i<=n;i++){
		if(labs(a[i]-a[i-1])!=k){
			f=0;
		}
	}
	sort(a+1,a+n+1);
	if(f){
		ll l=1,r=1e6,ans=0;
		while(l<=r){
			ll mid=(l+r)/2;
			if(check(mid,k)){
				l=mid+1;
				ans=mid;
			}
			else{
				r=mid-1;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n-1;i++){
		d[i]=labs(a[i+1]-a[i]);
	}
	ll cnt=0,Max=-1e17;
	for(int i=1;i<=n-1;i++){
		ll sum=0;
		cnt=1;
		for(int j=i;j<=n-1;j++){
			sum+=d[j]*cnt;
			if(sum<=m){
				cnt++;
			}
			else{
				break;
			}
		}
		Max=max(Max,cnt);
	}
	cout<<Max;
	return 0;
} 
