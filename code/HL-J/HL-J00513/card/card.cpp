#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],d[500005];
int number(int w)
{
	int num=0;
	string k;
	for(int i=0;i<=500004;i++)
	{
		d[i]=0;
	}
	for(int i=w-1;i<=n;i++)
	{
		k+=a[i];
		num++;
	}
	for(int i=0;i<num;i++)
	{
		for(int j=i;j<num;j++)
		{
			if(k[i]==k[j] && k[j]!=0 && k[i]!=0 && i!=j)
			{
				for(int x=i;x<j;x++)
				{
					if(k[x]==-1)
					{
					}
					else
					{
						k[x]=0;
					}
				}
				break;
			}
		}
	}
	for(int i=0;i<num;i++)
	{
		if(k[i]!=0)
		{
			d[a[i+w-1]]=1;
		}
	}
	for(int i=0;i<=500004;i++)
	{
		b[i]+=d[i];
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		number(i);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
