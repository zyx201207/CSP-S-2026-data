#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll n,m,a[N],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ll l=1;
	ll sum=0,d=0;
	for(ll r=2;r<=n;r++){
		sum+=1ll*(a[r]-a[r-1])*1ll*(r-l);
		d+=a[r]*1ll-a[r-1]*1ll;
		while(sum>m){
			sum-=d;
			d-=a[l+1]-a[l];
			l++;
		}
		ans=max(ans,r-l+1ll);
	}
	cout<<ans;
}

