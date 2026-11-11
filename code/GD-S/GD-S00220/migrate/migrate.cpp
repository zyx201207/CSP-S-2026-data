#include <iostream>
#include <map>
using namespace std;

typedef long long  ll;
ll c,t;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >> c >> t;
	
	while(t--){
		ll n,d;
		ll x[(int)2e6];
		map<ll, ll> vis;
		
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		cout << n*(n-1) << endl;
	}
	
	return 0;
}
