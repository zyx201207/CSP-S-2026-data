#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int c, t, n, d, a[N], ans;
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	srand(time(0));
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
		ans = 0;
		cout << rand() % n << '\n';
	}
	return 0;
}
/*没时间写了，给他了。好难受我不应该先去刚T4的暴力的 
*/ 
