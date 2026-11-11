#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
using namespace std;
#define int long long
#define fi first
#define se second
const int inf = 0x3f3f3f3f3f3f3f3f;
const int N = 3000010;
int C, T, n, d, a[N], L[N], R[N], c[2][N], tmp[N][2][2], cc[2][N];
bool flg[2][N], flgl[2][N], flgr[2][N], vis[N];
void solve() {
	scanf("%lld%lld", &n, &d);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for(int i = 1, j = 1; i <= n; i++) {
		while(j <= i && a[i] - a[j] > d) j++;
		L[i] = j;
	}
	for(int i = n, j = n; i >= 1; i--) {
		while(j >= i && a[j] - a[i] > d) j--;
		R[i] = j;
	}
	for(int i = 1; i <= n; i++) {
		flg[0][i] = (L[R[i]] == i) && R[i] != i;
		flg[1][i] = (L[R[i] - 1] == i && L[R[R[i]]] == R[i] - 1) && R[i] > i + 1 && R[R[i]] != R[i];
		flgl[0][i] = (L[R[i]] <= i) && R[i] != i;
		flgr[0][i] = (R[L[i]] >= i) && L[i] != i;
		flgl[1][i] = (L[R[i] - 1] <= i && L[R[R[i]]] == R[i] - 1) && R[i] > i + 1 && R[R[i]] != R[i];
		flgr[1][i] = (R[L[i] + 1] >= i && R[L[L[i]]] == L[i] + 1) && L[i] < i - 1 && L[L[i]] != L[i];
		c[1][L[L[i]]] += flgr[1][i];
		c[0][L[i]] += flgr[0][i];
		cc[0][R[i]] += (L[R[i] - 1] < i) && R[i] > i + 1;
		cc[1][L[i]] += (R[L[i] + 1] >= i) && L[i] < i - 1;
	}
	int Ans = 0;
	for(int i = 2; i <= n; i++)
		Ans += cc[0][i] * cc[1][i - 1];
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		for(int u = i; u <= i; u++) {
			tmp[u][1][0]++;
			vis[u] = 1;
			for(int fl = 0; fl <= 1; fl++) {
				if(fl) tmp[R[u]][0][0] += tmp[u][fl][0] * flgl[0][u];
				else tmp[R[u]][0][0] += tmp[u][fl][0] * flg[0][u];
				if(fl) tmp[R[u]][0][1] += tmp[u][fl][1] * flgl[0][u];
				else tmp[R[u]][0][1] += tmp[u][fl][1] * flg[0][u];
				if(fl) tmp[R[R[u]]][0][1] += tmp[u][fl][0] * flgl[1][u];
				else tmp[R[R[u]]][0][1] += tmp[u][fl][0] * flg[1][u];
			}
			Ans += tmp[u][1][0] * c[1][u];
			Ans += tmp[u][0][0] * c[1][u];
			Ans += tmp[u][1][1] * c[0][u];
			Ans += tmp[u][0][1] * c[0][u];
			if(R[u] == u) break;
		}
	}
	printf("%lld\n", Ans);
}
void clr() {
	for(int i = 0; i <= n + 5; i++) {
		memset(tmp[i], 0, sizeof(tmp[i]));
		for(int j = 0; j <= 1; j++)
			c[j][i] = cc[j][i] = 0;
		vis[i] = 0;
	}
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &C, &T);
	while(T--) {
		solve(); 
		clr();
	}
	return 0;
}
