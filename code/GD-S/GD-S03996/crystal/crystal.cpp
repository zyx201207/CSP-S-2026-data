#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll a[N];
ll sum[N];
ll num[N];
ll ans;
ll n,m;
ll find(int x){
	ll l=0,r=x-1;
	int need=x*a[x]-sum[x];
	while(l<r){
		ll mid=(l+r)/2;
		if(need-(mid*a[x]-sum[mid])<=m)r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,i-find(i));
		//cout<<i-find(i);
	}
	cout<<ans;
} 
