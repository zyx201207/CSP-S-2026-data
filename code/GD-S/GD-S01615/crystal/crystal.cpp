#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for(int i = l; i <= r; i++)
#define per(i, r, l) for(int i = r; i >= l; i--)
typedef long long ll;
ll read(){
	ll res = 0, flg = 1; char c = getchar();
	for(; c > '9' || c < '0'; c = getchar()) if(c == '-') flg = -flg;
	for(; c >= '0' && c <= '9'; c = getchar()) res = (res << 3) + (res << 1) + c - '0';
	return res * flg;
}
#define fpf(...) fprintf(stderr, __VA_ARGS__)
#define prt(...) fprintf(stdout, __VA_ARGS__)
int T, C;

#define file_name "crystal"

const int N = 5e5 + 5;

ll n, m;
ll a[N];
ll sum[N];
int ans = 0;

bool chk(int l, int r){
	return 1ll * a[r] * (r - l + 1) - (sum[r] - sum[l - 1]) <= m;
}

void Solve(){
	n = read(), m = read();
	rep(i, 1, n) a[i] = read();
	
	sort(a + 1, a + n + 1);
	sum[0] = 0;
	rep(i, 1, n) sum[i] = sum[i - 1] + a[i];
	
	for(int l = 1, r = 1; r <= n; r++){
		while(l < r && !chk(l, r)) l++;
		ans = max(ans, r - l + 1);
	}
	
	cout << ans;
}
signed main(){
	#ifdef lajishift
//		freopen("crystal5.in", "r", stdin);
//		freopen("my.out", "w", stdout);
	#elif defined(file_name)
		freopen(file_name ".in", "r", stdin);
		freopen(file_name ".out", "w", stdout);
	#endif

	T = 1, C = 0;
	while(T--) Solve();
	return 0;
}

