#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long ans;
long long a[N];
bool v[N];
int n,m;
bool cmp(long long x,long long y) {
	return x > y;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	ans = a[1];
	v[1] = true;
	for(int i = 2; i <= m; i++) {
		long long mx = -1e9,mi;
		for(int i = 1; i <= n; i++) {
			if(v[i] == true)continue;
			if(mx < (ans & a[i])) {
				mi = i;
			}
			mx = max(mx, ans & a[i]);
		}
		v[mi] = true;
		ans = mx;
	}
		cout << ans;
	return 0;
}
