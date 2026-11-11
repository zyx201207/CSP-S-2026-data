#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll C,T;
ll n,d;
ll a[2000005];
void solve11(){
	ll dt=a[2]-a[1];
	if(dt>d){
		cout<<0<<'\n';
		return;
	}
	ll tms=d/dt;
	if(tms<2||tms*2>n){
		cout<<0<<'\n';
		return;
	}
	cout<<(n-tms*2+1)<<'\n';
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
			solve11();
	}
}