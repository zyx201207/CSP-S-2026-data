#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
long long t;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	t=1ll*a[n];
	for(int i=n;i>n-m;--i)
		t&=1ll*a[i];
	printf("%lld\n",t);
	return 0;
}
