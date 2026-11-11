#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans=1,b[N],c[N];
int main()
{
	cin>>n>>m;
	while(n--)
	{
	
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			b[i]=a[i];
		}
		sort(b,b+n+1);
		unique(b,b+n+1);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				if(a[i]!=a[j])
				{
					break;
				}
				else
				{
					for(int k=j;k<=i;k++)
					{
						a[k]==0;
					}
					a[j]=a[i];
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==b[i])
			{
				c[b[i]]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<c[i];
	}
	return 0;
}