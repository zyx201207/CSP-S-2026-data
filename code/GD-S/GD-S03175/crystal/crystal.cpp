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
const int MAX=5e5+10, MAXM=1e3+10, MOD=1e9+7;
const ll INF=1e9;
int tc=1;
int n, ans;
ll a[MAX], dif[MAX], m;
void INIT() {
}
void EXE() {
	for (int i=1;i<=n;i++) scanf("%lld", &a[i]);
	sort(a+1, a+n+1);
	for (int i=2;i<=n;i++) dif[i]=a[i]-a[i-1];
	int l=1;
	for (int r=1;r<=n;r++) {
		m-=(r-l)*dif[r];
		while (m<0) m+=a[r]-a[l++];
		ans=max(ans, len(l, r));
	}
	printf("%d", ans);
}
void CLEAR() {
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	// scanf("%d", &tc);
	while (tc--) {
		scanf("%d %lld", &n, &m);
		INIT();
		EXE();
		CLEAR();
	}
	return 0;
}