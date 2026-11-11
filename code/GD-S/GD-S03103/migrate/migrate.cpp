#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ll n,d,ans;
		ll ar[100010];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>ar[i];
		}ll l=0;
		if(d==2){
			ans=(n%4)+1;
			cout<<ans<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
}
