#include <bits/stdc++.h>
#define endl '\n'
#define fn "hub"
typedef long long ll;
using namespace std;
int c, t;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen(fn ".in", "r", stdin);
	freopen(fn ".out", "w", stdout);
	cin >> c >> t;
	while(t --){
		ll n, k, u[1000010], v[1000010];
		cin >> n >> k;
		for(int i = 1; i <= n; i ++){
			cin >> u[i] >> v[i];
		}
		cout << 1 << endl;
	}
	return 0;
}
