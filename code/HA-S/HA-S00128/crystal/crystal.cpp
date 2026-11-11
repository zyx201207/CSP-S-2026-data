#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500005];
ll b[500005];
ll ans=-0x3f3f3f3f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<n;i++)
		b[i]=a[i+1]-a[i];
	ll s=0;
	ll c=0;
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			s+=b[j]*j;
			if(s>m)
				break;
			else
				c++;
		}
		ans=max(ans,c+1);
	}
	cout<<ans;
	return 0;
}
