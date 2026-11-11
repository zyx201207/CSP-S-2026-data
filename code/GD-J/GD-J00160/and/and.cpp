#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[200005],ans,b[200005],l;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	ans=pow(2,31)-1;
	for(int i=1;i<=min(n,m);i++)
		if(a[i]!=pow(2,ll(log2(a[i])))||(i==m&&(ans&a[i])!=0))ans&=a[i];
		else b[++l]=a[i],m++;
	if(m>n){
		sort(b+1,b+l+1);
		for(int i=1;i<=m-n;i++)
			ans&=b[i];
	}
	printf("%lld",ans);	
	return 0;
}
