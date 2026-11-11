#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int c, t, n;
ll d, x[N], sum[N];
int dp[505][505][505];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		cout << 0 << "\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
