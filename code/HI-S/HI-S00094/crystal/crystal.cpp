#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m;
ll a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int j=1; j<=n; j++) {
		cin>>a[j];
	}
	sort(a+1,a+n+1);
	for(int j=1; j<=n; j++) sum[j]=sum[j-1]+a[j];
	ll ans=1,l=1;
	for(ll r=2; r<=n; r++){
		ll cost=a[r]*(r-l+1)-(sum[r]-sum[l-1]);
		while(cost>m && l<=r){
			l++;
			cost=a[r]*(r-l+1)-(sum[r]-sum[l-1]);
		}
		if(l<=r) ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
