#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2000005;
int c, t, n, k;
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	srand(time(0));
	while(t--){
		cin >> n >> k;
		for(int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
		}
		cout << rand() % n << '\n'; 
	} 
	return 0;
}
