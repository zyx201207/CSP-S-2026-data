#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],i,c;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
 	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	c=a[n];
	for(i=n-1;i>=n-m+1;i--) c=c&a[i];
	printf("%lld",c);
	return 0;
}