#include<bits/stdc++.h>
using namespace std;
struct b{
	long long s, w, h;
} a[200009];
bool cmp(b l, b r) {
	if(l.w != r.w) return l.w > r.w;
	return l.s > r.s; 
}
long long ma = 0;
int n, m;
int main (  ) {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].s;
		long long cnt = a[i].s;
		while(cnt != 0) {
			if(cnt % 2 == 1) a[i].w++;
			cnt /= 2;
		}
		a[i].h = i;
	}
	sort(a + 1, a + n + 1, cmp);
	ma = a[1].s;
	for(int i = 2; i <= m; i++) ma &= a[i].s;
	cout << ma;
	return 0;
}
