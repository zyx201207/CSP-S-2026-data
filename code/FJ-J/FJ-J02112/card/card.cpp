#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],desk[500001],u[500001],w[500001],s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(u[j])
			{
				continue;
			}
			for(int k=1;k<=s;k++)
			{
				if(desk[k]==a[j])
				{
					for(int l=k;l<=s;l++)
					{
						desk[l]=0;
						u[l]=0;
					}
					s=k-1;
					break;
				}
			}
			desk[++s]=a[j];
			u[j]=1;
		}
	}
	for(int i=1;i<=s;i++)
	{
		printf("%d ",desk[s]);
	}
	return 0;
}
