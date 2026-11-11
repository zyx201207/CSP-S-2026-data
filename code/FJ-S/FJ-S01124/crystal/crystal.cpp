#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
ll n;
ll m;
ll a[N];
ll sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	ll l=1,r=2;
	ll ma=1;
	while(r<=n){
		ll ans=a[r]*(r-l);
		ll k=sum[r-1]-sum[l-1];
		ans-=k;
		if(ans<=m){
			ma=max(ma,r-l+1);
			r++;
		}
		else{
			l++;
		}
	}
	cout<<ma;
	return 0;
} 

