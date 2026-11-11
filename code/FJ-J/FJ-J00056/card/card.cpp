#include <bits/stdc++.h>
#define Flead(a,s,e,t) for (int a = s; a <= e; a += t)
using namespace std;

int n, m, a[500005], cnt[300005], lst[300005], now[500005], cur[300005];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("card.in", "r", stdin); freopen("card.out", "w", stdout);
	cin>>n>>m;
	bool specA = 1;
	Flead(i, 1, n, 1) {
		cin>>a[i];
		if (a[i] < a[i-1]) specA = 0;
	}
	if (m == 1) {
		cout<<n;
		return 0;
	}
	if (specA) {
		Flead(i, 1, m, 1) cout<<upper_bound(a+1, a+1+n, i)-a-1<<' ';
		return 0;
	}
	Flead(i, 1, n, 1) {
		if (a[i] == a[i-1]) {
			for (int j = 1; j <= m; j++) cnt[j] += cur[j];
			continue;
		}
		int ptr = 0;
		memset(lst, 0, sizeof(int) * (m+3)); memset(cur, 0, sizeof(int) * (m+3));
		Flead(j, i, n, 1) {
			if (lst[a[j]] == 0 || lst[a[j]] > ptr || now[lst[a[j]]] != a[j]) {
				now[++ptr] = a[j];
				lst[a[j]] = ptr;
			}
			ptr = lst[a[j]];
		}
		Flead(j, 1, ptr, 1) cur[now[j]] = 1;
		Flead(j, 1, m, 1) cnt[j] += cur[j];
	}
	for (int i = 1; i <= m; i++) cout<<cnt[i]<<' ';
	return 0;
}
