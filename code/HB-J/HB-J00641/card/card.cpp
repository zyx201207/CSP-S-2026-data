#include<bits/stdc++.h>
using namespace std;
int a[300005],c[300005],d[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int l=0;
		for(int j=1;j<=n;j++)c[j]=0;
		for(int j=i;j<=n;j++)
		{
			int f=0;
			for(int k=1;k<=l;k++)
			{
				if(c[k]==a[j])
				{
					f=k;
					break;
				}
			}
			if(f)
			{
				l=f;
				for(int k=f+1;k<=n;k++)
				{
					c[k]=0;
				}
			}
			else c[++l]=a[j];
		}
		l=1;
		while(c[l])
		{
			d[c[l]]++;
			l++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<d[i]<<" ";
	}
	return 0;
}
