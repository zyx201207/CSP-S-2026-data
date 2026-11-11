#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m;
ll a[500005],sum[500005],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		sum[i]=a[i]-a[i-1];
	}
	for(ll i=1;i<=n;i++){
		ll cc=m,j=1;
		while(cc>=sum[j+i]*j&&j+i<=n){
			cc-=j*sum[j+i];
			j++;
		}
		ans=max(ans,j);
	}
	cout<<ans;
	return 0;
}
