#include<bits/stdc++.h>
using namespace std;
long long s[6000000],a[6000000],sum[4000000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,i,j,x=0,y=0,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(i=1;i<=n;i++)
	{
		x=1;
		for(j=i;j<=n;j++)
		{
			for(k=1;k<x;k++)
			{
				if(a[k]==s[j])
				{
					for(int r=k;r<x;r++)
					{
						a[r]=0;
						x--;
					}
					break;
				}
			}
			a[x]=s[j];
			x++;
		}
		for(j=1;j<x;j++)
		{
			sum[a[j]]++;
		}
	}
	for(i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
}
