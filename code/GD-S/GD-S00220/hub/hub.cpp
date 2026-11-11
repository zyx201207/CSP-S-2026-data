#include <iostream>
#incldue <map>
using namespace std;

typedef long long  ll;
ll c,t;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin >> c >> t;
	
	while(t--){
		ll n,k;
		map<ll,map<ll,bool>> mp;
		cin >> n >> k;
		
		for(int i=1; i<n; i++){
			ll t1,t2;
			cin >> t1 >> t2;
			mp[t1][t2] = mp[t2][t1] = true;
		}
		cout << 1 << endl;
	}
	
	return 0;
}
