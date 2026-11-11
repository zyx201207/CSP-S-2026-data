#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n, m, a[N], ans[N], q[N], id[N];
bool vis[N];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) scanf("%d", &a[i]);
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++)
			vis[a[j]] = id[a[j]] = 0;
		int tail = 0;
		for(int j=i; j<=n; j++) {
			if(!vis[a[j]]) q[++tail] = a[j],
				vis[a[j]] = 1, id[a[j]] = tail;
			else {
				for(int k=tail; k>id[a[j]]; k--) vis[q[k]] = 0;
				tail = id[a[j]], id[a[j]] = tail;
			}
		}
		for(int j=1; j<=tail; j++) ans[q[j]]++;
	} for(int i=1; i<=m; i++) printf("%d ", ans[i]);
	return 0;
}
