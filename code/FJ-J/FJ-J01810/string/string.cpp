#include <bits/stdc++.h>
using namespace std;
int n,a[100005],ans;
char c[100005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&a[i],&c[i]);
	}
	if(n<=1)
	{
		printf("0");
		return 0;
	}
	bool x=true;
	for(int i=2;i<=n;i++)
	{
		if(c[i]!=c[i-1])
		{
			x=false;
			break;
		}
	}
	if(x)
	{
		printf("0");
		return 0;
	}
	for(int i=(n+1)/2;i>=1;i--)
	{
		if(c[i]!=c[n+1-i])
		{
			ans++;
			c[i]=c[n+1-i];
			bool flag=true;
			for(int j=1;j<=n;j++)
			{
				if(c[i]!=c[n+1-i])
				{
					flag=false;
				}
			}
			if(flag) 
			{
				printf("%d",ans);
				return 0;
			}
		}
	}
	return 0;
}
