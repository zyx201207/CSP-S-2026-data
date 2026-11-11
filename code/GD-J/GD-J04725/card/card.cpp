#include <bits/stdc++.h>
using namespace std;
long long n,m,a[700000],b[700000],c[700000];
int main()
{
	freopen("card.in","r","stdin");
	freopen("card.out","w","stdout");
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int u=1;u<n;u++)
		{
			b[u]=0;
		}
		for(int k=1+i;k<=n;k++)
		{
			
			b[k]=a[k];
			for(int l=1+i;l<k;l++)
			{
				if(b[k]==b[l])
				{
					for(int j=l;j<k;j++)
					{
						b[j]=0;
					}
				}
			}
		}
		for(int p=1;p<=n;p++)
		{
			if(b[p]!=0)
			{
				c[b[p]]++;
			}
		}
	}
	for(int i=1;i<m;i++)
	{
		cout<<c[i]<<" ";
	}
	cout<<c[m];
	return 0;
}
