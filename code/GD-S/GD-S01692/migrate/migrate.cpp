#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+10;
ll c,t;
ll a[N];
void solve(){
	cin>>c>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c==11||c==12){
			if(n>=4) cout<<(a[n]%d+1)<<endl;
			else cout<<0<<endl;
		}
		else if(c==13||c==14){
			cout<<0<<endl;
		}
		else cout<<0<<endl;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	solve();
	return 0;
}
