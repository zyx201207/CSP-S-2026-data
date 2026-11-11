#include <bits/stdc++.h>
#define enl putchar('\n')
#define ys puts("YES")
#define md int mid=l+r>>1
#define len(l, r) ((r)-(l)+1)
#define fst first
#define snd second
using ll=long long;
using ull=unsigned long long;
using pii=std::pair<int, int>;
using namespace std;
const int MAX=2e6+10, MAXM=1e3+10, MOD=1e9+7;
const ll INF=1e9;
int cid, tc=1;
int n;
int mxr[MAX], mxl[MAX];
ll x[MAX], D, ans, dp[MAX], cnt[MAX];
void n2() {
	for (int u=1;u<=n;u++) {
		fill(dp+1, dp+n+1, 0);
		fill(cnt+1, cnt+n+1, 1);
		for (int v=u+1;v<=n;v++) {
			int lst=max(u, mxl[v]);
			dp[v]=dp[lst]+1;
			if (lst==v) break;
			else if (lst+1==v||dp[lst]<dp[lst+1]) cnt[v]*=cnt[lst];
			else if (lst+2==v||dp[lst+1]<dp[lst+2]) cnt[v]*=(cnt[lst]+cnt[lst+1]);
			else cnt[v]=3;
			if (cnt[v]==2) ans++;
		}
	}
}
void d2() {
	for (int i=1;i<=n;i++) if (i+1<mxr[i]) ans+=mxr[mxr[i]-1]-mxr[mxr[i]-2];
}
void eqdif() {
	ll d=D/(x[2]-x[1]);
	if (d<=1) return;
	ans=max(0ll, len(d<<1, n));
}
void INIT() {
	ans=0;
}
void EXE() {
	for (int i=1;i<=n;i++) scanf("%lld", &x[i]);
	bool ck1=false, ck2=true;
	for (int i=1;i<=n;i++) {
		mxl[i]=lower_bound(x+1, x+n+1, x[i]-D)-x;
		mxr[i]=upper_bound(x+1, x+n+1, x[i]+D)-x-1;
		if (mxl[i]==1&&mxr[i]==n) ck1=true;
		if (i>2&&x[i]-x[i-1]!=x[i-1]-x[i-2]) ck2=false;
	}
	if (n<=5000) n2();
	else if (ck2) eqdif();
	else if (ck1) d2();
	else n2();
	printf("%lld\n", ans);
}
void CLEAR() {
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d %d", &cid, &tc);
	while (tc--) {
		scanf("%d %lld", &n, &D);
		INIT();
		EXE();
		CLEAR();
	}
	return 0;
}
