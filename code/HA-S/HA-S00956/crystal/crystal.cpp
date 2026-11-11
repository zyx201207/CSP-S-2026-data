#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5;
ll n,m,ans;
ll a[N],s;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(ll i=1;i<=n;++i) cin>>a[i];
	
	sort(a+1,a+n+1);
	s=a[2]-a[1];
	ll sp=s;
	while(m>sp){
		ans++;
		m-=sp;
		sp+=s;
		if(ans>n) break;
	}
	
	if(ans>=n) cout<<n;
	else cout<<ans+1;
	
	return 0;
}
