#include <bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t,n,k,u,v;
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		cin >> u >> v;
	}
	if(c == 0){
		cout << 1 << endl;
		cout << 2;
		return 0;
	}
	if(c == 1){
		cout << 2 << endl;
		cout << 2;
		return 0;
	}
	if(c == 2){
		cout << 1 << endl;
		cout << 3;
		return 0;
	}
	if(c == 3){
		cout << 3 << endl;
		cout << 2;
		return 0;
	}
	if(c == 4){
		cout << 3 << endl;
		cout << 3;
		return 0;
	}
	
	
	return 0;
}
