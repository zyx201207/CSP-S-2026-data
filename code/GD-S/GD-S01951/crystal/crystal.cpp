#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],sum[N];
bool chk(ll x){
	for(ll l=1;l<=n-x+1;l++){
		ll r=l+x-1;
		if(x*a[r]-(sum[r]-sum[l-1])<=m)
			return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	ll l=1,r=n,mid=0;
	while(l<r){
		mid=(l+r+1)>>1;
		if(chk(mid))
			l=mid;
		else
			r=mid-1;
	}
	cout<<l<<'\n';
	return 0;
} 
