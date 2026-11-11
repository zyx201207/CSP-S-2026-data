#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[100],n,m,b[100];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}

	for(int i=1;i<=n;i++)
	{
		b[i]=a[i];
	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[j]==a[i])
				{
					for(int k=i;k<=j;k++)
						{
							b[k]=0;
						}
				}
		
		}
	
	}
	
	
	
	
	
	
	for(int i=1;i<=n;i++)
	{
		cout<<b[i]<< " ";
	}
	return 0;
}
