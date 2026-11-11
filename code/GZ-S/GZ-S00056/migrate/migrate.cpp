//GZ-S00056,彭翊瑄，北师大贵阳附中 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vl vector<ll>
#define pll pair<ll,ll>
#define fi first
#define se second
const int N=5e5+5;
void ji(){
	ll n,d,ans=0;
	cin>>n>>d;
	vl a(n+1);
	ll di;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	di=a[2]-a[1];
	ll d2=d/di;
	ll step=2*d2-1;
	for(ll i=1;i<=n;i++){
		if(i+step<=n)ans++;
		if((i-1-step)%d2==0&&i-1-step>0){
			ans++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c;
	ll t=1;
	cin>>c>>t;
	while(t--){
		ji();
	}
	return 0;
} 
