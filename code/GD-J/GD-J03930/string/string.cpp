#include <bits/stdc++.h>
using namespace std;
const int N=2e5+7;
long long n, a[N], ans;
char c[N];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for(int i=1; i<=n; i++)
		cin>>a[i]>>c[i];
	for(int l=1, r=n; l<r; ) {
		if(c[l]!=c[r]) ans+=min(a[l], a[r]);
		if(a[l]>a[r]) a[l]-=a[r], r--;
		else a[r]-=a[l], l++;
	}
	printf("%lld", ans);
	return 0;
}
