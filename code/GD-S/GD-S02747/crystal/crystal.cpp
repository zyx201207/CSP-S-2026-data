#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
ll n,m;
ll a[N];
ll s[N];
bool check(ll x,ll i){
	ll sum=a[i]*(i-x)-s[i-1]+s[x-1];
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	ll ans=0;
	for(int i=n;i>=1;i--){
		ll l=1,r=i;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(check(mid,i)&&i-mid+1>1){
				//cout<<mid<<' '<<i<<'\n';
				r=mid-1;
				ans=max(ans,i-mid+1);
			}
			else {
				l=mid+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
