#include <iostream>
#include <algorithm>
#define ll long long 
#define R(a,b,c) for(ll a=b;a<=c;a++)
#define E(a,b,c) for(ll a=b;a>=c;a--)
using namespace std;
ll a[500025];
ll qs[500025];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	R(i,1,n)cin>>a[i];
	sort(a+1,a+1+n);
	R(i,1,n)qs[i]=qs[i-1]+a[i];
	ll ans=1;
	R(i,1,n){
		ll l=0,r=i;
		while(l+1<r){
			ll mid=l+r>>1;
			if(qs[i]-qs[mid-1]+m>=(i-mid+1)*a[i])r=mid;
			else l=mid;
		}
		ans=max(ans,i-r+1);
//		cout<<i<<" "<<r<<'\n';
	}
	cout<<ans<<'\n';
	return 0;
}
//14:38
//14:42
