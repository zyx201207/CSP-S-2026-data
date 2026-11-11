#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],s[N],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1;
	for(int i=1;i<=n;i++)
	{
		while(a[i]*(i-l+1)-s[i]+s[l-1]>m)l++;
		ans=max(ans,i-l+1ll);
	}
	printf("%lld",ans);
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7

*/
