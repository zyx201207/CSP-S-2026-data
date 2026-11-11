#include<bits/stdc++.h>
using namespace std;

	int dui[n+2],zhuo[n+2];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,ju=1;

	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>dui[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>dui[i];
	}
	for(int i=ju;i<=n;i++)
	{
		zhuo[i]=dui[i];
		for(int j=1;j<=i;j++)
		{
			dui[i]=dui[i+1];
		}
		for(int j=1;j<=i;j++)
		{
			if(zhuo[i]==zhuo[j])
			{
				for(int k=j;k<=i;k++)
				{
					dui[k]=zhuo[k];
					zhuo[k]=0;
				}
			}
		}
	}
}
