#include <bits/stdc++.h>
using namespace std;
int c, t, i, j, k, d, ans, n, m, a, b;
int f[5005][5005], s[5005], p[5005][5005], q[1000000], x[5005], cnt[5005][5005];
void bfs (int b){
	int i, j, k, a;
	memset (s, 54, sizeof(s));
	memset (q, 0, sizeof(q));
	q[1] = b;
	s[b] = 0;
	for (i=j=1; i<=j; i++) {
		a = q[i];
		for (k=1; k<=n; k++){
			if (s[k] > s[a] + p[a][k]) {
				s[k] = s[a] + p[a][k], q[++j] = k;
			}
		}
	}
	for (i=1; i<=n; i++){
		if (a == i) continue;
		if (f[b][i] > s[i]) f[b][i] = f[i][b] = s[i], cnt[b][i] = cnt[i][b] = 1;
		else if (f[b][i] == s[i]) cnt[b][i]++, cnt[i][b]++;
	}
}
int main (){
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	scanf ("%d%d", &c, &t);
	for (i=1; i<=t; i++){
		scanf ("%d%d", &n, &d);
		ans = 0;
		memset (cnt, 0, sizeof(cnt));
		memset (f, 54, sizeof(f));
		for (j=1; j<=n; j++){
			scanf ("%d", &x[j]);
		}
		for (j=1; j<=n; j++){
			for (k=1; k<=n; k++){
				if (j == k) continue;
				if (abs(x[j]-x[k]) <= d) p[j][k] = p[k][j] = abs(x[j]-x[k]);
			}
		}
		for (j=1; j<=n; j++){
			bfs (j);
		}
		for (j=1; j<=n; j++){
			for (k=1; k<=n; k++){
				if (abs(j-k)==1 || j == k) continue;
				if (cnt[j][k] == 2) {
					ans++;
				}
			}
		}
		printf ("%d\n", ans/2);
	}
	return 0;
}
