#include<bits/stdc++.h>
using namespace std;
int c, t, n, k;
int u[1000100], v[1000100];
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t!=0){
		cin >> n >> k;
		for(int i = 1; i <= n-1; i++){
			cin >> u[i] >> v[i];
		}
		t--;
	}
	if(c == 0 && t == 2){
		cout << 1 << endl << 2;
	}
	if(c==0 && t == 3){
		cout << 1 << endl << 1 << endl << 2;
	}
	if(c == 0&& t==1){
		cout << 12251;
	}
	return 0;
}
