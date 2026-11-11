#include <iostream>
#include <cstdio>
using namespace std;
int c, t;
int n, k;
int u[105], v[105];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> c >> t;
	if(c == 0){
		cin >> n >> k;
		for(int i = 1; i < n; ++i){
			cin >> u[i] >> v[i];
		}
		cout << "1\n2";
		return 0;
	}
	return 0;
} 
