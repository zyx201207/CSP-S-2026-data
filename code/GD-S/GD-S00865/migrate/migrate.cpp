#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
const ll N=2e6+5;
ll a[N],p[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		if(abs(a[1]-a[0])>d){
			cout<<"0"<<'\n';
		}
		else{
			for(ll i=1;i<=n;i++){
				p[i+1]++;
				if(i+d+1<=n)p[i+d+1]--;
			}
			for(ll i=1;i<=n;i++){
				p[i]=p[i-1]+p[i];
			}
			ll ans=0;
			for(ll i=1;i<=n;i++){
				if(p[i]==2)ans++;
			}
			cout<<ans<<'\n';
			for(ll i=1;i<=n;i++){
				a[i]=0;
				p[i]=0;
			}
		}
	}
} 
