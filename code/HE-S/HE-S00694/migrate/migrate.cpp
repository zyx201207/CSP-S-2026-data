#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 2e6+10 , Inf = 0x7f7f7f7f;

int n , m;
int a[N];

inline void solve(){
	int ans = 0 , sum = 0;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a+1 , a+n+1);
	sum = abs(a[2] - a[1]);
	if(m/2 < sum){cout << 0 << "\n"; return;}
	if(m % sum != 0) m = (m/sum)*sum;
	for(int i = 1 ; i <= n ; i++){
		if(a[i]+m*2-sum <= a[n]) ans++;
		else break;
	}
	cout << ans << "\n";
}

signed main (){	
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	int c , T; cin >> c >> T;
	while(T--){
		solve();
	}
	return 0;
} 
