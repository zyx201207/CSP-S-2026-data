#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	vector<ll> f(n+5,0),a(n+5);
	ll sum=(1<<30)-1;
	for(ll i=1;i<=n;i++) {
		cin>>a[i];
		sum&=a[i];
	}
	if(n==m) cout<<sum<<endl;
	f[0]=(1<<30)-1;
	for(ll i=1;i<=n;i++){
		for(ll j=i;j>=1;j--){
			if(i==j) f[j]=(f[j-1]&a[i]);
			else f[j]=max(f[j],(f[j-1]&a[i]));
		}
	}
	cout<<f[m]<<endl;
	return 0;
}


