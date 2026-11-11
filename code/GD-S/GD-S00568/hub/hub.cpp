#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, t;
const int T = 5 + 10;
int n[T], k[T];
const int N = 1e5 + 10;
int u[N], v[N];
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	for (int i = 1;i <= t;i++){
		cin >> n[i] >> k[i];
		for (int j = 1;j <= n[i];j++){
			cin >> u[j] >> v[j];
		}
	}
	
	return 0;
}
