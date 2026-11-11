#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n,m) for(ll i=n;i<=m;i++)
#define disrep(i,n,m) for(ll i=n;i>=m;i--)
ll c,t;
ll a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		ll cnt = 0;
		ll n,d;cin>>n>>d;
		if(n<=3){
			cout<<0<<"\n";
			return 0;
		}
		rep(i,1,n){
			ll x;cin>>x;
			if(x-a[i-1]>d&&i>1){
				a[i]=x;
				break;
			}
			a[i]=x;
		}
		
	}
	
	
	return 0;
}
