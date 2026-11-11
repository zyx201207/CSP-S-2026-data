#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("crystal.in","r",stdin)
	//freopen("crystal.out","w",stiout);
	int n,m,a[500001],i,sum=0,max,c=0;
	cin>>n>>m;
	int w=m;
	int b[n+1];
	for(i=1;i<=n;i++)
	{
		b[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int y=1;y<=n;y++)
		{
			if(a[i]==y)
			{
				b[y]++;
				continue;
			}
		}
	}
	max=1;
	for(i=1;i<=n;i++)
	{
		if(b[i]>max)
			max=i;
	    if(b[i]!=max&&b[i]!=0)
	    {
			c++;
		}
	}
	if(c==0)
	{
		max=n;
	}
	sum+=b[max];
	for(i=max-1;i>=1;i--)
	{
		for(int j=1;j<=m;j++)
		{
			if(i+j==max)
			{
				if(m<=b[i]*j)
				{
					sum+=m;
					break;
				}
				else
				{
					m-=b[i]*j;
					sum+=b[i];
				}
			}
		}
	}
	int x=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]!=i)
			x++;
	}
	if(x==0)
	{
		sum=1;
		for(i=max-1;i>=1;i--)
		{
			for(int j=1;j<=w;j++)
			{
				if(i+j==max)
				{
					if(w<=b[i]*j)
					{
						sum+=w;
						break;
					}
					else
					{
						w-=b[i]*j;
						sum+=b[i];
					}
				}
			}
		}
		cout<<sum;
	}
	else
	{
		cout<<sum;
	}
	return 0;
}
