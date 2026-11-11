#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll c,t;
ll a[200001];
ll q[200001];
ll s[200001];
ll sum[200001];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;

	while(t--){
		ll n,d;
		cin>>n>>d;
		for(ll i=1;i<=n;i++)cin>>a[i];
		for(ll i=1;i<=n;i++){
			q[i]=a[i]-a[i-1];
		}
		
		for(ll i=2;i<=n;i++){
			ll j=0;
			while(i+j<n&&a[i+j]-a[i-1]<d)j++;
			if(a[i+j]-a[i-1]>d)j--;
			s[i]=j;
		}
	//	for(int i=1;i<=n;i++)cout<<s[i]<<' ';
	//	cout<<'\n';
		ll ans=0;
		for(ll i=2;i<n;i++){
			if(s[i]==s[i+s[i]]){
				ans++;
				ll j=i+s[i]+s[i];
				while(s[j]==d){
					j++;
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
} 
