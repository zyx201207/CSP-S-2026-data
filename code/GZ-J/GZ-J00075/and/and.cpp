//GZ-J00075,彭翊瑄，北师大贵阳附中 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vl vector<ll>
#define pll pair<ll,ll>
#define fi first
#define se second
void ji(){
	ll n,m;
	cin>>n>>m;
	vl a(n+1);
	for(ll i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		sort(a.begin(),a.end());
		cout<<a[n];
	}
	if(n==m){
		ll ans=a[1];
		for(ll i=1;i<=n;i++){
			ans&=a[i];
		} 
		cout<<ans;
	}
	
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll t=1;//cin>>t;
	while(t--){
		ji();
	} 
	return 0;
} 
