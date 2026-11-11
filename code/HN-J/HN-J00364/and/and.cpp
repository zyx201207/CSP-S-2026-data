#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(m==1)
	{
		sort(a+1,a+n+1,greater<int>());
		printf("%d",a[1]);
		return 0;
	}
	else if(m==2)
	{
		int t=a[1]&a[2];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i]&a[j]>t&&i!=j)
				{
					t=a[i]&a[j];
				}
			}
		}
		printf("%d",t);
	}
	else
	{
		sort(a+1,a+n+1,greater<int>());
		int t2=a[1]&a[2];
		for(int i=3;i<=m;i++)
		{
			t2=t2&a[i];
		}
		printf("%d",t2);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
