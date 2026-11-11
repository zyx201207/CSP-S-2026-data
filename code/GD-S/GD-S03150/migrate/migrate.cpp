#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		ll n,d,ans=0;
		cin>>n>>d;
		vector<ll> a(n+2),b(n+2);
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		ll dxd=2;
		for(int i=1;i<=n;++i){
			while(abs(a[dxd]-a[i])<=d&&dxd<=n){
				dxd++;
			}
			b[i]=dxd-1;
		}
		for(int i=1;i<=n;++i){
			if(b[i]==n)break;
			ans+=b[b[i]]-b[i];
			if((b[b[i]]-b[i])%d==0)ans--;
		}
		cout<<ans<<endl; 
	}

	return 0;
}

