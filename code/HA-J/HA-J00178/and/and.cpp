#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],maxx=-0x3f3f3f3f,cnt,ans;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)ans=a[i];
		maxx=max(maxx,a[i]);
	}
	ll s1=0;
	ll y=n;
	while(y>0){
		if(y%2==0)s1++;
		y/=2;
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	else if(m==2){
		ll w=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				ll x=a[i]&a[j];
				w=max(w,x);
			}
		}
		cout<<w;
		return 0;
	}
	else if(m==n){
		ll ans=a[1];
		for(ll i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(s1%2==0&&s1!=0 ){
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	cout<<a[n-1];
	return 0;
}
