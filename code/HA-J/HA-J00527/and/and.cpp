#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n==1)
	{
		int ret=0;
		for(int i=1;i<=m;i++)
		{
			ret=max(ret,a[i]);
		}
		printf("%d",ret);
	}
	else if(m==n)
	{
		int ret=a[1];
		for(int i=2;i<=m;i++)
		{
			ret=ret&a[i];
		}
		printf("%d",ret);
	}
	else
	{
		int ret=0;
		for(int i=1;i<=m;i++)
		{
			for(int j=i+1;j<=m;j++)
			{
				ret=max(ret,a[i]&a[j]);
			}
		}
		printf("%d",ret);
	}
	return 0;
}
