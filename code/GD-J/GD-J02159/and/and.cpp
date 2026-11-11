#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long n,m;
long long a[N];
bool cmp(long long x,long long y) {
	return x>y;
}
long long qmax(int x,int cs,long long za) {
	if(cs>=m) return za;
	else if(x>=n-m+cs) return 0;
	return max(qmax(x+1,cs+1,za&a[x]),qmax(x+1,cs,za));
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=0; i<n; i++) scanf("%lld",&a[i]);
	sort(a,a+n,cmp);
	printf("%lld",qmax(1,1,a[0]));
	return 0;
}
