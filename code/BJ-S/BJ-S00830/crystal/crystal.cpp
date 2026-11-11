#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
ll n,a[N],m,ans=1,sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(ll r=1,l=1;r<=n;r++){
		ll cost=(r-l+1ll)*a[r]-(sum[r]-sum[l-1]);
		while(l<=r&&cost>m){
			l++;
			cost=(r-l+1ll)*a[r]-(sum[r]-sum[l-1]);
		}
		ans=max(ans,r-l+1ll);
	}
	cout<<ans;
	return 0;
}
