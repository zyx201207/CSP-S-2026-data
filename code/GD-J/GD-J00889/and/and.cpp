#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	printf("%lld",a[n-m+1]);
	return 0;
} 
