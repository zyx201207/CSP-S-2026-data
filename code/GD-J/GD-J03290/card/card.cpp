#include <bits/stdc++.h>
#define endl '\n'
#define fn "card"
typedef long long ll;
using namespace std;
ll n, m;
int main(){
	freopen(fn ".in", "r", stdin);
	freopen(fn ".out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	cin >> n >> m;
	for (ll i = 1; i <= m; i ++){
		cout << n << " ";
	}
	return 0;
}
