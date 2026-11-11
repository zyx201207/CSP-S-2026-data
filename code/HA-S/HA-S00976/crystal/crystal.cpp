#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	long a[500005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll il=a[n];
	ll lins;
	for(int i=n-1;i>=1;i--){
		lins=il-a[i];
		il=a[i];
		a[i]=lins;
	}
	a[n]=0;
	for(int i=n-1;i>=1;i--){
		a[i]=a[i]+a[i+1];
	}
	ll ans=1;
	while(n>1){
		n--;
		ll mm=m;
		ll jishu=1;
		for(ll i=n;i>=1;i--){
			ll ii=a[i]-a[n+1];
			if(mm<ii)break;
			mm-=ii;
			jishu++;
		}
		ans=max(jishu,ans);
	}
	cout<<ans<<'\n';
	return 0;
} 
