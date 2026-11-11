#include<bits/stdc++.h>
#define ll long long
using namespace std;;

const int N=2e6+5;

int c,T;
ll n,d;
ll x[N];


void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(x[2]-x[1]>=d){
		cout<<0<<'\n';
		return ;
	}
	ll ans=max(0ll,n-d/(x[2]-x[1])*2+1);
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
