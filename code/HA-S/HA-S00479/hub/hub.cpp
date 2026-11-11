#include<bits/stdc++.h>
using namespace std;

int c, T;
int n, k;

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while(T --){
		cin >> n >> k;
		for(int i = 1; i <= n; i ++){
			int u, v;
			cin >> u >> v;
		}
		
		cout << (n / k) - 1 << endl;
	}
	
	
	
	return 0;
}
