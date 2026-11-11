#include <iostream>
using namespace std;

long long c,t,n,k;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		int m = n / 2;
		for(int i = 1,u,v;i < n; i++) cin >> u >> v;
		cout << (m - k + 2) / 3 << endl;
	}
	
	return 0;
}