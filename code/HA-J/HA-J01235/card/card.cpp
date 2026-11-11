#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5 * 1e5 + 50;
int stk[MAXN], instk[MAXN], head;
int d[MAXN], cnt[MAXN];
int n, m;
int a[MAXN], vis[MAXN];

int main () {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	scanf ("%d %d", & n, & m);
	for (int i = 1; i <= n; i++) scanf ("%d", & a[i]);
	for (int i = 1; i <= n; i++) {
		head = 0;
		for (int l = 1; l <= n; l++) stk[l] = instk[l] = d[l] = vis[l] = 0;
		for (int j = i; j <= n; j++) {
			if (!instk[a[j]] && !vis[a[j]]) {
				stk[++head] = a[j];
				instk[a[j]] = 1;
				d[a[j]] = head;
			} else	if (instk[a[j]]) {
				for (int k = vis[a[j]] + 1; k <= head; k++) {
					instk[stk[k]] = d[stk[k]] = 0;
					vis[stk[k]] = 1;
				}
				head = d[a[j]] + 1;
			}
//			for (int p = 1; p <= head; p++) printf ("%d ", stk[p]);
//			puts("");
		}
		for (int i = 1; i <= head; i++) {
			cnt[stk[i]]++;
		}
	}
	for (int i = 1; i <= m; i++) printf ("%d ", cnt[i]);
	return 0;
}
