#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
int n;
ll a[N], m, pre[N];
bool check(int x) {
	ll need = 9e18;
	for(int i=1; i+x-1<=n; i++) {
		int j = i+x-1;
		need = min(need, x*a[j]-pre[j]+pre[i-1]);
	} return need <= m;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d %lld", &n, &m);
	for(int i=1; i<=n; i++)
		scanf("%lld", &a[i]);
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++)
		pre[i] = pre[i-1]+a[i];
	int l = 1, r = n;
	while(l<r) {
		int mid = l+r+1>>1;
		if(check(mid)) l = mid;
		else r = mid-1;
	} printf("%d", l);
	return 0;
}
