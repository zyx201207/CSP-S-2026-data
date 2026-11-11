#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
vector<lo> a;
lo c,t,n,d;
int add(int i,int v) {
	if(i == v) return v+1;
	int x = d;
	while(i < v && a[i+1]-a[i] <= x) i++,x -= a[i+1]-a[i];
	return i;
}
int ad(int i,int u) {
	if(i == u) return u-1;
	int x = d;
	while(i > u && a[i]-a[i-1] <= x) i--,x -= a[i]-a[i-1];
	return i;
}
bool check(int u,int v) {
	int x = u,y = v,z = 0;
	for(int i = u;i <= v;i = add(i,v)) z++;
	for(int j = 1;j < z;j++) x = add(x,v);
	y = ad(y,u);
	return x != y;
}
int main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	lo x,y;
	scanf("%lld%lld",&c,&t);
	while(t--) {
		scanf("%lld%lld",&n,&d);
		for(int i = 1;i <= n;i++) {
			scanf("%lld",&x);
			a.push_back(x);
		}
		x = 0;
		if(c == 11 || c == 12) {
			y = d/(a[1]-a[0]);
			for(int i = 0;i < n;i++) for(int j = i+2*y;j < n;j += y) x += y-1;
			printf("%lld\n",x);
			continue;
		}
		if(c == 13 || c == 14) {
			for(int i = 0;i < n;i++) if(a[i]+2*d <= a[n-1]) x++;
			printf("%lld\n",x);
			continue;
		}
		for(int i = 0;i < n;i++) for(int j = i+1;j < n;j++) if(check(i,j)) x++;
		printf("%lld\n",x);
	}
	return 0;
}
