#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll n,d;
ll x[N];
ll a[N];
ll ans=0;
vector<ll> e[N];
ll w[N];
ll sj(){
	ll ii=0,jj=0,ans1=d;
	for(ll i=1;i<=n;i++){//u
		for(ll j=n;j>=1;j++){//v
			if(abs(x[j]-x[i])<=d||abs(i-j)<=1) break;
			else{
				ans1-=a[j-1];
				if(ans1==a[j-1]) j--;
			}
			jj=j;
			ans1=d;		
		}
		ans1-=a[i];
		if(ans1==a[i]) i++;
		ii=i;
		ans1=d;
	}
	if(ii!=jj) ans++;
	ii=0,jj=0;
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(),cout.tie();
	ll c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
		}
		for(ll i=1;i<n;i++){
			a[i]=x[i+1]-x[i];
		}
		sj();
		cout<<ans<<'\n';
	}
}
