#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,t,ans,n,d;
pair<ll,ll> aa(ll a,ll b,vector<ll>v){
	ll ans1=0,mn=0X3F3F3F3F;
	if(v[b]-v[a]<=d)return {1,v[b]-v[a]};
	if(v[b]-v[a]>d&&b-a==1)return {-1,-1};
	for(ll i=a+1;i<b;i++){
		auto c=aa(a,i,v),d=aa(i,b,v);
		if(c.first==-1||d.first==-1)return {-1,-1};
		ll e=c.first+d.first+1;
		if(e<mn)ans1=1,mn=e;
		else if(e==mn)ans1++;
	}
	return {ans1,mn};
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		vector<ll>a(n+5,0);
		for(ll i=1;i<=n;i++)cin>>a[i];
		ans=0;
		for(ll i=1;i<n;i++){
			for(ll j=i+1;j<=n;j++){
				auto q=aa(i,j,a);
				//cout<<i<<' '<<j<<':'<<q.first<<' '<<q.second<<'\n';
				if(q.first==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

