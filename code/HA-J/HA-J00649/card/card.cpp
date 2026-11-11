#include <bits/stdc++.h>
#define lb(n) ((n) & (-(n)))
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 5e5 + 5, M = 5e5 + 5;

int n, m, a[N];
int lst[M], cnt[N];
ll b[N], dp[N], s[M];

inline 
void add(int x, ll v) {
	for (; x <= m; x += lb(x)) b[x] += v;
}

inline 
ll ask(int x) {
	ll cnt = 0;
	for (; x; x -= lb(x)) cnt += b[x];
	return cnt;
}

int main() {
	cin.tie(0) -> sync_with_stdio(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i], lst[a[i]] = i;
	for (int i = 1; i <= m; i ++) cnt[i] = n - lst[i] + 1;
	for (int i = 1; i <= n; i ++) a[i] = cnt[a[i]];
	for (int i = 1; i <= n; i ++) lst[a[i]] = i;
//	for (int i = n; i >= 1; i --) {
//		nxt[i] = lst[a[i]], lst[a[i]] = i;
//		int x = i;
//		while (x <= n) {
//			ans[a[x]] ++;
//			while (nxt[x] != 0) x = nxt[x];
//			x ++;
//		}
//	}
	for (int i = 1, k = m; i <= n; i ++) {
		if (lst[a[i]] == i) k --;
		s[a[i]] ++;
		dp[i] = max(s[a[i]], i - ask(k));
		add(a[i], dp[i]);
//		cout << dp[i] << " ";
	}
	for (int i = 1; i <= m; i ++) cout << dp[lst[cnt[i]]] << " ";
	
	
	return 0;
}

