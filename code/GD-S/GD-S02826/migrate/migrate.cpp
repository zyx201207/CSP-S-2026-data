#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,t;
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);cout.tie(nullptr);
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
cin>>c>>t;
while(t--)
{
ll n,d;
cin>>n>>d;
vector<ll>a(n);
for(ll &x:a)cin>>x;
ll delta=(a[1]-a[0]),ans=0;
for(int i=2;i<=n;++i)
{
	ll cnt=d/delta;
	ll t=cnt*d-delta*i;
	if(t>=delta&&t<2*delta)
	{
		ans+=n-i;
	}
}cout<<ans<<"\n";
	
}
return 0;
}
