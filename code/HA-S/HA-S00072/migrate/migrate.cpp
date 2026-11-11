#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t;
ll n,m;
ll a[200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ll ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		sort(a+1,a+n+1);
		if(n<2*m){
			cout<<0<<"\n";
			continue;
		}
		for(int i=n;i>=2*m;i--)
		ans+=i/(2*m);
		cout<<ans<<"\n";
	}
	return 0;
}
