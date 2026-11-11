#include<bits/stdc++.h>
using namespace std;
int n,m;
long long s[200010],ans=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&s[i]);
		//printf("\nd:%d\n",i);
	}
	sort(s,s+n);
	ans=s[n-1];
	for(int i=n-1;i>=n-m;i--)
	{
		ans=ans&s[i];
	}
	printf("%lld",ans);
	return 0;
}
