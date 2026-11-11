#include <bits/stdc++.h>
#define re register
#define fst first
#define snd second
#define int long long
#define chmax(a,b) (a = max(a,b))

using namespace std;

typedef pair<int,int> pii;
const int N = 2e6 + 10,inf = (int)(1e18) + 10;
const int mod = 998244353;
int cid,n,D;
int a[N],to[N],dp[N],f[N];
pii pre[N];

inline int read(){
	int r = 0,w = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') w = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		r = (r << 1) + (r << 3) + (c ^ 48);
		c = getchar();
	}
	return r * w;
}

struct{
	#define lowbit(x) ((x) & -(x))

	int tr[N];
	
	inline void init(int n){ fill(tr,tr + n + 3,0); }
	
	inline void modify(int x,int k){
		for (re int i = x;i <= n;i += lowbit(i)) ((tr[i] += k) += mod) %= mod;
//		for (re int i = x;i <= n;i++) ((tr[i] += k) += mod) %= mod;
	}
	inline void modify(int l,int r,int k){
//		cerr << l << " " << r << " mdf\n";
		modify(l,k); modify(r + 1,-k);
	}
	
	inline int query(int x){
		int sum = 0;
		for (re int i = x;i;i -= lowbit(i)) (sum += tr[i]) %= mod;
		return sum;
	}
	
	#undef lowbit
}T;

inline void solve(){
	int ans = 0;
	n = read(),D = read();
	for (re int i = 1;i <= n;i++) a[i] = read();
	for (re int i = 0;i <= n + 3;i++) pre[i] = {0,0};
	for (re int i = 2;i <= n;i++){
		if (a[i] - a[1] > D){ to[1] = i - 1; break; }
	}
	for (re int i = 2;i <= n;i++){
		to[i] = to[i - 1];
		while (to[i] < n && a[to[i] + 1] - a[i] <= D) to[i]++;
	}
	if (n == 1) return puts("0"),void();
	if (n <= 300){
		for (re int s = 1;s < n;s++){
			dp[s] = 0,f[s] = 1;
			for (re int i = s + 1;i <= n;i++) dp[i] = inf,f[i] = 0;
			for (re int i = s;i <= n;i++){
				for (re int j = i + 1;j <= to[i];j++){
					if (dp[j] > dp[i] + 1) dp[j] = dp[i] + 1,f[j] = f[i];
					else if (dp[j] == dp[i] + 1) f[j] = min(3ll,f[i] + f[j]);
				}
			}
			for (re int i = s + 1;i <= n;i++) ans += (f[i] == 2);
		}
	}
	else if (n <= 5000){
		for (re int s = 1;s < n;s++){
			int it1 = s + 1,it2 = s + 1;
			for (re int i = s + 1;i <= n;i++) dp[i] = inf,f[i] = 0;
			dp[s] = 0,f[s] = 1;
			T.init(n); T.modify(s,s,1);
			for (re int i = s;i <= n;i++){
				int val = T.query(i);
				while (it1 <= n && dp[it1] < dp[i] + 1) it1++;
				while (it2 <= n && dp[it2] <= dp[i] + 1) it2++;
//				cerr << s << " " << i << " " << it1 << " " << it2 << " " << dp[i] << " " << T.query(i) << " ???\n";
				T.modify(it1,it2 - 1,val); T.modify(it2,to[i],val);
				for (re int j = it2;j <= to[i];j++){
//					cerr << dp[j] << " " << dp[i] + 1 << " !!!!\n";
					dp[j] = dp[i] + 1;
//					T.modify(j,j,val);
				}
//				for (re int j = i + 1;j <= to[i];j++){
//					if (dp[j] > dp[i] + 1) dp[j] = dp[i] + 1,f[j] = f[i];
//					else if (dp[j] == dp[i] + 1) f[j] = min(3ll,f[i] + f[j]);
//				}
			}
			for (re int i = s + 1;i <= n;i++) ans += (T.query(i) == 2);
		}
	}
	else{
		int d = a[2] - a[1];
		if (D < 2 * d) ans = 0;
		else{
			int t = D / d;
			int tmp = 2 + t * 2;
			ans = max(0ll,n - tmp + 3);
		}
//		if (2 * d <= D && D < 3 * d) ans = n - 3;
//		else ans = 0;
	} printf("%lld\n",ans);
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cid = read(),T = read();
	while (T--) solve();
	return 0;
}

/*
x[to[x[to[i]]]] - x[to[x[to[i]]]] <= d

0 1
4 2
1 2 3 4

0 1
5 2
1 2 3 4 5

0 1
3 1
1 5 10

0 1
5 3
-2 -1 0 1 2

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/ 
