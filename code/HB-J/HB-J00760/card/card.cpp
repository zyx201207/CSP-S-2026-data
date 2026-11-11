#include<iostream>
#include<cmath>
using namespace std;
int n,m,a[300000],q[7000000],ids,h[7000000];
int check(int df)
{
	for(int k=1;k<=ids;k++)
	{
		if(q[k]==df)
		{
			return 0;
		}
	}
	return 1;
}
void find(int df)
{
	int flag=0,kj;
	for(int k=1;k<=ids;k++)
	{
		if(flag==1)
		{
			q[k]=0;
		}
		else if(q[k]==df)
		{
			q[k]=0;
			flag=1;
			kj=k-1;
		}
		else
		{
			continue;
		}
	}
	ids=kj;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	ids=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(check(a[j])==0)
			{
				find(a[j]);
			}
			else
			{
				q[ids+1]=a[j];
				ids++;
			}
		}
		for(int k=1;k<=ids+1;k++)
		{
			h[q[k]]++;
		}
		for(int k=1;k<=ids+1;k++)
		{
			q[k]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<h[i]<<" ";
	}
}
