#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node {
	ll s;
	char c;
}a[200005]; 
ll n,ans;

int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for (ll i = 1;i <= n;i++) scanf("%lld %c",&a[i].s,&a[i].c);
	ll l = 1,r = n;
	while (l < r) {
		if (a[l].s > a[r].s) {
			if (a[l].c != a[r].c) ans += a[r].s;
			a[l].s -= a[r].s,r--;
		}
		else if (a[l].s < a[r].s) {
			if (a[l].c != a[r].c) ans += a[l].s;
			a[r].s -= a[l].s,l++;
		}
		else {
			if (a[l].c != a[r].c) ans += a[l].s;
			l++,r--;
		}
	} 
	printf("%lld\n",ans); 
	return 0;
}
