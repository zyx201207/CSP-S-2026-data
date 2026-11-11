#include<bits/stdc++.h>
using namespace std;

long long n,m,a[1000001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]); 
	sort(a+1,a+n+1); 
	printf("%lld ",a[n-m+1]);
	return 0;
}
