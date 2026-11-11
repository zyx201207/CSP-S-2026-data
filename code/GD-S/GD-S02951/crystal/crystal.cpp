#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n;
ll m,a[N],c[N],s[N];
bool check(int x) {
	for(int i=1; i+x-1<=n; i++) {
		int r=i+x-1;
		if(s[i]-s[r]-c[r]*(r-1)<=m) {
			return 1;
		}
	}
	return 0;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1; i<=n; i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=n; i>=1; i--)c[i]=a[n]-a[i];
	for(int i=n; i>=1; i--)s[i]=s[i+1]+c[i];
	int l=0,r=n+1;
	while(l+1<r) {
		int mid=l+(r-l)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	printf("%d",l);
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
/*
5 5
1 2 4 8 9
*/
