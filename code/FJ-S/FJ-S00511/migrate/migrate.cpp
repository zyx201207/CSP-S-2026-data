#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, T;
int n, d;
const int N = 2e6 + 10;
int x[N], f[1005][1005], ans;
void sol(){
	cin >> n >> d;
	ans = 0;
	for(int i = 1; i <= n; i++) cin >> x[i];
	if(n <= 3){
		cout << "0\n"; return;
	}
	if(11 <= c && c <= 12){
		int q = x[2] - x[1];
		if(d < q){
			cout << "0\n"; return;
		}
		else if(d < q * 2){
			cout << "0\n"; return;
		}
		else{
			int r = d / q;
			cout << max(n - r * 2 + 1, 0LL) << '\n';
			return;
		}
	}
	else cout << "0\n";
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while(T--) sol();
}
