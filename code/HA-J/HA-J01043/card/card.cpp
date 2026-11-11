#include<bits/stdc++.h>
using namespace std;
long long b[300010],l;
short o[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=k;i<=n;i++)
		{	
			for(int j=i-1;j>=k;j--)
			{
				if(a[i]==a[j]&&i>k)
				{
					for(int kk=j;kk<i;kk++)
					{
						o[a[kk]]=1;
					}
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(o[j]!=1)
			{
				b[j]++;
			}
			else
			{
				o[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
