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
void write(ll x, char c = '\n'){
	if(x < 0){ putchar('-'); x = -x; }
	static int stk[40], top = 0;
	do { stk[++top] = x % 10; x /= 10; } while(x);
	while(top){ putchar('0' + stk[top--]); }
	putchar(c);
}
#define fpf(...) fprintf(stderr, __VA_ARGS__)
#define prt(...) fprintf(stdout, __VA_ARGS__)
int T, C;

#define file_name "migrate"

const int N = 2e6 + 5;
const int inf = 0x3f3f3f3f;

int n;
ll d;
ll x[N];

namespace SUB1{
	pair<ll, ll> f[N];
	pair<ll, ll> merge(pair<ll, ll> a, pair<ll, ll> b){
		if(a.first == b.first) return {a.first, a.second + b.second};
		else return min(a, b);
	}
	void solve(){
		n = read(), d = read();
		rep(i, 1, n) x[i] = read();
		
		int ans = 0;
		rep(l, 1, n){
//			fpf("l: %d\n", l);
			f[l] = {0, 1};
			rep(r, l + 1, n){
				f[r] = {inf, 0};
				per(i, r - 1, l){
					if(x[r] - x[i] > d) break;
					f[r] = merge(f[r], f[i]);
				}
				if(f[r].second > 0) f[r].first++;
				if(f[r].second == 2) ans++; 
//				fpf("r: %d, f[r] = (%lld, %lld)\n", r, f[r].first, f[r].second);
			}
		}
		write(ans);
	}
}

namespace SUB2{
	void solve(){
		
	}
}

namespace SUB3{
	void solve(){
		n = read(), d = read();
		rep(i, 1, n) x[i] = read();
		puts("0");
	}
}

void Solve(){
	n = read(), d = read();
	rep(i, 1, n) x[i] = read();
	cout << 1ll * n * (n - 1) / 2 << '\n';
}
signed main(){
	#ifdef lajishift
//		freopen("migrate3.in", "r", stdin);
	#elif defined(file_name)
		freopen(file_name ".in", "r", stdin);
		freopen(file_name ".out", "w", stdout);
	#endif

	C = read(), T = read();
	if(C <= 8){
		while(T--) SUB1::solve();
		return 0;
	}
	if(C == 11 || C == 12){
		while(T--) SUB2::solve();
		return 0;
	}
	if(C == 13 || C == 14){
		while(T--) SUB3::solve();
		return 0;
	}
	while(T--) Solve();
	return 0;
}

