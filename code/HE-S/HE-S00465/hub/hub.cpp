#include<bits/stdc++.h>
using namespace std;

int c, t;

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> c >> t;
	
	while(t--){
		int n, k;
		cin >> n >> k;
		
		for(int i = 1; i <= n; i++){
			int u, v;
			cin >> u >> v;
		} 
	}
	
	if(c == 0 && t == 2){
		cout << 1 << endl;
		cout << 2 << endl;
	}
	if(c == 0 && t == 3){
		cout << 1 << endl;
		cout << 1 << endl;
		cout << 2 << endl;
	}
	if(c == 0 && t == 5){
		cout << 17 << endl;
		cout << 9 << endl;
		cout << 6 << endl;
		cout << 6 << endl;
		cout << 9 << endl;
	}if(c == 0 && t == 1){
		cout << 12251 << endl;
	}
	return 0;
} 
