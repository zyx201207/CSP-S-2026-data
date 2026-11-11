#include<bits/stdc++.h>
#define ll long long
#define DEBUG(x) cerr << #x << " = " << x
#define pc putchar
#define pb push_back
#define empb emplace_back
#define st first
#define nd second
using namespace std;
namespace KinoHimari{
	ll read(){
		ll x = 0, f = 1; char ch = getchar();
		for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') f = -1;
		for(; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 - (ch - '0');
		return f == 1 ? -x : x;	
	}
	void write(ll x){
		if(x == LLONG_MIN) return printf("%lld", x), void();
		if(x < 0) pc('-'), x = -x;
		if(x >= 10) write(x / 10);
		pc('0' + x % 10);
	}
	const int inf = 0x3f3f3f3f, N = 505, M = 5e5 + 5;
	const ll INF = 1e18;
	int C, n, m, d, q, w[M], k[N], tot[M]; ll f[N][N];
	vector<int> a[N], t[N];
	vector<pair<int, int>> v[M];
	void cmin(ll &x, ll y){ x = min(x, y); }
	int main(){
		C = read(), n = read(), m = read(), d = read(), q = read();
		for(int i = 1; i <= m; i++) w[i] = read();
		for(int i = 1; i <= n; i++){
			k[i] = read(); a[i].resize(k[i]), t[i].resize(k[i]);
			for(int j = 0; j < k[i]; j++) a[i][j] = read(), t[i][j] = read(), tot[a[i][j]]++;
		}
		for(int i = 1; i <= m; i++) v[i].reserve(tot[i]);
		for(int i = 1; i <= n; i++) for(int j = 0; j < k[i]; j++) v[a[i][j]].empb(i, t[i][j]);
		memset(f, 0x3f, sizeof(f));
		for(int i = 1; i <= n; i++) f[i][i] = 0;
		for(int i = 1; i <= m; i++)
			for(int j = 0; j < v[i].size(); j++)
				for(int k = j + 1; k < v[i].size(); k++)
					cmin(f[v[i][j].st][v[i][k].st], v[i][j].nd + v[i][k].nd), f[v[i][k].st][v[i][j].st] = f[v[i][j].st][v[i][k].st];
		for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cmin(f[i][j], f[i][k] + f[k][j]);
		for(int i = 1, x, y; i <= q; i++){
			x = read(), y = read();
			ll ans = INF;
			for(int j = 0; j < v[x].size(); j++) for(int k = 0; k < v[y].size(); k++) cmin(ans, f[v[x][j].st][v[y][k].st] + v[x][j].nd + v[y][k].nd);
			ans += w[x] + w[y];
			write(ans), pc('\n');
		}
		return 0;	
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	return KinoHimari :: main();	
}
