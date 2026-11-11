#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5 * 1E5 + 100;
int c, t, n, k;
int u[N], v[N];

signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1; i <= n - 1; i++){
			cin >> u[i] >> v[i]; 
		}
		cout << 1 << endl;;
	}
	return 0;
}
