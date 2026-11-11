#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=2e5+10;
int n,m,a[N],s[N],ans=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(m==1)
	{
		int ans=-1;
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		printf("%d",ans);
		return 0;
	}
	if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		printf("%d",ans);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int sum=a[i];
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j;k<=j+m-2&&k<=n;k++) sum&=a[k];
			ans=max(ans,sum);
		}
	}
	printf("%d",ans);
	return 0;
}
