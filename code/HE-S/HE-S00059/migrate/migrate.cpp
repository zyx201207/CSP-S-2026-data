#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6;
ll n,d,x[N+5],ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
		}
		if(x[n]-x[1]+1<=d*2){
			ll cnt=0;
			for(ll i=2;i<n;i++){
				if(x[i]-x[1]<=d&&x[n]-x[i]<=d) cnt++;
			}
			if(cnt==2) ans++;
			cout<<ans<<endl;
			continue;
		}
		for(ll i=1;i<n;i++){
			for(ll j=i+1;j<=n;j++){
				ll cnt=0;
				for(ll k=i+1;k<j;k++){
					if(x[k]-x[i]<=d&&x[j]-x[k]<=d) cnt++;
				}
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
