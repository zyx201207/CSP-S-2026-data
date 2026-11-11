#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,sum,ans;
ll a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	bool f=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) f=0;
	}
	sort(a+1,a+n+1);
	if(f){
		sum=0,ans=0;
		while(sum<=m){
			ans++;
			sum+=ans;
		}
		if(sum>m) ans--;
		cout<<ans;
		return 0;
	}
	ll maxx=0;
	for(ll i=2;i<=n;i++){
		sum=0,ans=1;
		ll t=m;
		for(ll j=i-1;j>=1;j--){
			ans++;
			t-=abs(a[i]-a[j]);
			if(t<0) break;
		}
		if(t<0) ans--;
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
