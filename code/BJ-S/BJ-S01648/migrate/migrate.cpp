// Calm down.
// Think TWICE, code ONCE.
#include<bits/stdc++.h>
#define pb push_back
#define popcnt __builtin_popcountll
#define debug printf("Passed line %d\n", __LINE__)

using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> PII;

template<typename T> inline void read(T &x){
	x = 0; bool F = 0; char c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') F = 1;
	for (;isdigit(c);c = getchar()) x = x*10+(c^48);
	if (F) x = -x;
}

template<typename T1, typename ...T2> inline void read(T1 &x, T2 &...y){read(x), read(y...);}

template<typename T> inline void checkmax(T &x, const T &y){if (x<y) x = y;}

template<typename T> inline void checkmin(T &x, const T &y){if (x>y) x = y;}

const int N = 2e6+5, M = 10;
int r[N], msk[5][5][5], cnt[N][M+1], tot, z[M+2][4], n;
ll x[N], d, ans;

inline void solve(int p, int st){
	int mul = cnt[p][st], f[4], L, R, dp[4], lim, val[4], m;
	for (int j = 1;j<=3;j++) val[j] = r[max(p+j-3, 0)]; val[0] = p;
	for (int i = 1;i<=3;i++) dp[i] = z[st][i];
	dp[2] += dp[3], dp[1] += dp[2];
	for (int j = 1;j<=3;j++){
		if (dp[j]!=2) continue;
		R = val[j], L = max(val[j-1], p)+1;
		// printf("%d %d\n", L, R);
		if (L<=R) ans += 1ll*(R-L+1)*mul;
	}
	memset(f, 0, sizeof(f));
	m = r[p]-3;
	for (int j = 3;j>=1;j--){
		lim = max(0, max(val[j-1], p)-m);
		for (int k = val[j]-m;k>lim;k--) f[k] = dp[j];
	}
	checkmin(f[1], 1), checkmin(f[2], 3), checkmin(f[3], 3);
	cnt[r[p]][msk[f[1]][f[2]][f[3]]] += mul;
}

inline void solve(){
	read(n, d); ans = 0;
	for (int i = 1;i<=n;i++) read(x[i]);
	for (int i = 1;i<=n;i++){
		r[i] = r[i-1];
		while (r[i]<n && x[r[i]+1]<=x[i]+d) r[i]++;
		memset(cnt[i], 0, sizeof(cnt[i]));
	}
	int dp[4], f[4], p, L, R, val[4], m, lim;
	for (int i = 1;i<=n;i++){
		cnt[i][msk[0][0][1]]++;
		if (i == r[i]) continue;
		for (int j = 1;j<=M;j++){
			if (!cnt[i][j]) continue;
			solve(i, j);
		}
	}
	printf("%lld\n", ans);
}

inline void Set(int x, int y, int Z, int t){
	swap(x, Z);
	msk[x][y][Z] = t;
	z[t][1] = x, z[t][2] = y, z[t][3] = Z;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t; read(c, t);
	for (int i = 1;i<=3;i++){
		for (int j = 0;j<=3;j++){
			if (j && j<i) continue;
			if (!j) Set(i, j, 0, ++tot);
			else if (i+j>=3) tot++, Set(i, j, 0, tot), Set(i, j, 1, tot);
			else Set(i, j, 0, ++tot), Set(i, j, 1, ++tot);
		}
	}
	while (t--) solve();
	return 0;
}