#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int N=1e6;
ll c,T;
ll n,d;
ll a[N+10];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	ll dd;
	if(a[2]-a[1]>=0) dd=a[2]-a[1];
	else dd=a[1]-a[2];
	if(d<=dd) cout<<0<<'\n';
	else{
		if(d/dd<=1) cout<<0<<'\n';
		else{
			ll l=d/dd;
			ll op=2*l-1;
			if(n-op<=0) cout<<0<<'\n';
			else cout<<n-op<<'\n';
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}

