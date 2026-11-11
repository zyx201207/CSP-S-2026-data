#include <bits/stdc++.h>
#define int long long
#define lowbit(x) x&(-x)
using namespace std;
const int N = 2e5 + 10;
int n,m,c,d,q;
int a[N],fa[N],w[N],k,t[N];
int l,r;
int find (int x) {
	if (fa[x] == x) return x;
	return fa[x] == find(fa[x]);
}
void add(int x,int w) {
	for (int i = x; i <= n; i += lowbit(i)) {
		t[i] += w;
	}
}
void findd(int x,int w) {
	for (int i = x; i; i -= lowbit(i)) {
		t[i] -= w;
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	int sum = 0;
	while (n--) {
		sum = 0;
		cin >> k;
		for (int i = 1; i <= 2*k; i++) {
			cin >> t[i];
			sum += t[i];
		}
	}
	while (q--) {
		int x,y;
		cin >> x >> y;
		cout << sum << '\n';
	}
	return 0;
}/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
