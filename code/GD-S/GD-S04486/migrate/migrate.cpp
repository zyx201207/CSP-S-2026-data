#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+7;
ll c,t,n,d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		map<ll,int>mp;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			mp[a[i]]=1;
		}
		ll ans=0LL;
		for(int i=1;i<=n;i++) if(mp[a[i]+d+(d-1)]&&mp[a[i]+d]) ans++;
		cout<<ans<<"\n";
	}	
	return 0;
}
