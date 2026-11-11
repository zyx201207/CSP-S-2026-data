#include<bits/stdc++.h>
using namespace std;
long long a[500005],a1[500005],c[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			long long num=0;
			for(int k=i;k<=j;k++)
			{
				if(a1[k]==a[j])
				{
					num=1;
				}
				if(num==1)
				{
					a1[k]=0;
				}
			}
			a1[j]=a[j];
		}
		for(int j=i;j<=n;j++)
		{
			if(a1[j]!=0)
			{
				c[a1[j]]++;
				a1[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<' ';
	}
	return 0;
}
